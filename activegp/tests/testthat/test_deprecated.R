test_that("expected C update works", {
  # Function to discover ASM on
  set.seed(123)
  nvar <- 3
  n <- 100
  f <- function(x)(DiceKriging::hartman3(x) + rnorm(1, sd = 0.1))
  
  # Initial design
  design <- matrix(runif(nvar*n), ncol = nvar)
  response <- apply(design, 1, f)
  model <- mleHomGP(design, response, known = list(beta0 = 0)) 
  
  C_hat <- C_GP(model)
  
  xnew <- matrix(runif(nvar), ncol = nvar)
  
  ynew <- f(xnew)
  ypred <- predict(model, x = xnew)
  
  C_up_mean <- update_C2(C = C_hat, xnew = xnew, ypred$mean)
  
  C_up_fast <- expectCup(C = C_hat, xnew = xnew)
  
  expect_true(norm(C_up_fast - C_up_mean) < 1e-8)
  
  
  
})