test_that("Multiple y batch update works", {
  # Function to discover ASM on
  set.seed(123)
  nvar <- 6
  n <- 50
  r <- 1
  f <- function(x) sin(sum(x))
  true_sub <- c(1,1) / sqrt(2)
  
  # Initial design
  design <- matrix(runif(nvar*n), ncol = nvar)
  response <- apply(design, 1, f)
  model <- mleHomGP(design, response, known = list(beta0 = 0)) 
  
  C_hat <- C_GP(model)
  
  # For one new design
  xnew <- matrix(runif(nvar), ncol = nvar)
  draws <- 2000
  ydraws <- rnorm(draws)
  
  up <- lapply(ydraws, function(ynew) up <- update(C_hat, xnew, ynew)$mat)
  evals <- eval_ys(C_hat, xnew, ydraws)
  
  diffs <- sapply(1:draws, function(i) norm(up[[i]] - evals[[i]]))
  expect_true(max(diffs) < 1e-5)
  
  # for a batch of new designs, test updated C value
  library(MASS)
  nnew <- 1
  Xnew <- matrix(runif(nvar * nnew), ncol = nvar)
  pnew <- predict(model, x = Xnew, xprime = Xnew)
  Zdraws <- t(mvrnorm(n = draws, mu = pnew$mean, Sigma = pnew$cov + diag(pnew$nugs, nnew)))
  
  evalsb <- eval_ys(C_hat, Xnew = Xnew, Zdraws = Zdraws)
  upb <- lapply(1:draws, function(i) up <- update(C_hat, Xnew, Zdraws[,i])$mat)
  diffsb <- sapply(1:draws, function(i) norm(upb[[i]] - evalsb[[i]]))
  expect_true(max(diffsb) < 1e-5)
  
  upb2 <- lapply(1:draws, function(i) up <- update_C3(C_hat, Xnew, Zdraws[,i]))
  diffsb2 <- sapply(1:draws, function(i) norm(upb2[[i]] - evalsb[[i]]))
  expect_true(max(diffsb2) < 1e-5)
  
  # now check variance expression
  vars <- matrix(apply(array(unlist(upb), c(36,draws)), 1, var),6)
  
  element_wise_var_batch <- function(C, Xnew){
    if(is.null(nrow(Xnew))) Xnew <- matrix(Xnew, nrow = 1)
    nvar <- ncol(Xnew)
    
    preds <- predict(object = C_hat$model, x = Xnew, xprime = Xnew)
    new_lambda <- preds$nugs
    vni <- solve(preds$cov + diag(new_lambda, length(new_lambda))) * C_hat$model$nu_hat
    ret <- activegp:::get_betagamma_batch(C_hat, Xnew)
    res <- matrix(NA, nvar, nvar)
    for (i in 1:nvar){
      for (j in i:nvar){
        res[i,j] <- res[j,i] <- crossprod(ret$BETA[,i,j], vni %*% ret$BETA[,i,j]) + sum(vni %*% ret$GAMMA[,,i,j] %*% vni * (ret$GAMMA[,,i,j] + t(ret$GAMMA[,,i,j])))
      }
    }
    return(res)
  }
  
  ewv <- model$nu_hat * element_wise_var_batch(C_hat, Xnew)
  expect_equal(vars, ewv, tolerance = 3e-5) # Ok if nnew = 1
  
  # Finally the batch criteria expressions

  # trace
  test <- model$nu_hat * C_tr_batch(C_hat, Xnew)
  ref <- batch_crit(C_hat, Xnew, crit = "tr", nsamp = 10000)
  ref2 <- activegp:::acq_tr(upb)
  expect_equal(test, ref, tolerance = 2e-4)
  expect_equal(test, ref2, tolerance = 2e-4)
  expect_equal(C_tr_batch(C_hat, Xnew[1,]), C_tr(C_hat, Xnew[1,]))
  
  # var1
  # test <- model$nu_hat * sqrt(C_var_batch(C_hat, Xnew))
  # ref <- batch_crit(C_hat, Xnew, crit = "var", nsamp = 10000)
  # ref2 <- activegp:::acq_cvar(upb)
  expect_equal(C_var_batch(C_hat, Xnew[1,]), C_var(C_hat, Xnew[1,]))
  
  # var2
  # test <- model$nu_hat * sqrt(C_var2_batch(C_hat, Xnew))
  # ref <- batch_crit(C_hat, Xnew, crit = "var2")
  expect_equal(C_var2_batch(C_hat, Xnew[1,]), C_var2(C_hat, Xnew[1,]))
  
})

#' C Variance Norm
#' Gives the Frobenius norm of the variance of C , that is of E[(C - E[C])^2] = E[(C - E[C])(C - E[C])]
scvar <- function(Cs) {
  MU <- Reduce(function(i,j)i + j, Cs) / length(Cs)
  DELTA <- lapply(Cs, function(C) C - MU)
  DELTA2 <- lapply(DELTA, function(DELTA) DELTA %*% DELTA)
  SIGMA <- Reduce(function(i,j) i + j, DELTA2) / length(DELTA2)
  return(norm(SIGMA, 'F'))
}

covtypes <- c("Gaussian", "Matern3_2", "Matern5_2")
for (ct in 1:length(covtypes)) {
  test_that(paste(covtypes[ct], " Kernel: Variance of the trace/frob. norm of Cn+q is correct"),{
    set.seed(1234)
    nvar <- 3
    n <- 20
    f <- function(x)(DiceKriging::hartman3(x) + rnorm(1, sd = 0.1))
    
    # Initial design
    design <- matrix(runif(nvar*n), ncol = nvar)
    response <- apply(design, 1, f)
    model <- mleHomGP(design, response, lower = rep(1e-4, nvar),
                      covtype = covtypes[ct], upper = rep(0.5, nvar), known = list(beta0 = 0)) 
    
    C_hat <- C_GP(model)
    
    samp_trs <- an_trs <- samp_cvs <- an_cvs <- samp_var2 <- an_var2 <- rep(NA, 25)
    q <- 3
    for(j in 1:25){
      Xnew <- matrix(runif(nvar*q), ncol = nvar)
      
      ynew <- apply(Xnew, 1, f)
      ypred <- predict(model, x = Xnew, xprime = Xnew)
      
      # sample trace of C(ynew)
      nsamp <- 1e4
      tr_samps <- rep(NA, nsamp)
      
      Cs_samp <- matrix(NA, nsamp, length(C_hat$mat))
      
      for(i in 1:nsamp){
        ynewi <- mvrnorm(1, ypred$mean, ypred$cov + diag(ypred$nugs + model$nu_hat * model$eps, q))
        Ci <- update_C3(C_hat, Xnew, ynewi)
        Cs_samp[i,] <- as.vector(Ci)
        tr_samps[i] <- sum(diag(Ci))
      }
      
      Cvsamp <- matrix(diag(var(Cs_samp)),3)
      samp_cvs[j] <- sqrt(sum(Cvsamp^2))
      an_cvs[j] <- sqrt(C_var_batch(C_hat, Xnew))
      
      samp_trs[j] <- var(tr_samps)
      an_trs[j] <- C_tr_batch(C_hat, Xnew)
      
      samp_var2[j] <- scvar(lapply(1:nsamp, function(i) matrix(Cs_samp[i,], nrow = nvar)))
      an_var2[j] <- sqrt(C_var2_batch(C_hat, Xnew))
    }
    
    expect_equal(model$nu_hat*an_trs, samp_trs, tolerance = 1e-1)
    expect_equal(model$nu_hat*an_cvs, samp_cvs, tolerance = 1e-1)
    expect_equal(model$nu_hat*an_var2, samp_var2, tolerance = 1e-1)
  })
}



  