fun_estimate <- function(oy, od, oz, bound, ...) {
    
    n <- length(oy)
    K <- n:1
    jh <- 1e-08
    
    ittm <- 100
    c0 <- 0
    cn <- 0
    nb <- c(0, 0)
    ob <- nb + 0.1
    of <- Inf
    decision <- FALSE
    
    while ((sum(abs(round(10000 * ob) - round(10000 * nb))) > 0) & (cn < ittm)) {
        ob <- nb
        b <- as.numeric(nb) + cbind(c(0, 0), c(jh, 0), -c(jh, 0), c(0, jh), -c(0, 
            jh))
        gamma1 <- exp(-oz %x% matrix(b[1, ], nrow = 1))
        gamma2 <- exp(-oz %x% matrix(b[2, ], nrow = 1))
        Lambda1 <- apply(gamma1, 2, function(x, od, K) cumsum(x * od/K), od = od, 
            K = K)
        Lambda2 <- apply(gamma2, 2, function(x, od, K) cumsum(x * od/K), od = od, 
            K = K)
        P <- exp(-Lambda2)
        PL <- rbind(1, P[1:(n - 1), ])
        R <- apply(PL * od * gamma1/K, 2, cumsum)/P
        denom <- gamma1 + gamma2 * R
        u1 <- -(oz * od) %*% (gamma1/denom) + oz %*% (R/denom)
        u2 <- -(oz * od) %*% (gamma2 * R/denom) + oz %*% (log(denom/gamma1)/gamma2) - 
            oz %*% (R/denom)
        u <- rbind(u1, u2)
        s <- sum(u[, 1]^2)
        
        h <- cbind((u[, 2] - u[, 3])/jh/2, (u[, 4] - u[, 5])/jh/2)
        h[1, 2] <- h[1, 2]/2 + h[2, 1]/2
        h[2, 1] <- h[1, 2]
        
        ep <- 1e-05
        while (!((det(h) > 1e-04) && all(diag(h) > 0))) {
            ep <- 2 * ep
            h <- h + ep * diag(2)
        }
        
        t <- 1
        po <- -solve(h) %*% u[, 1]
        bc <- nb + t * po
        
        idb <- sum((bc > log(bound) + c(0, c0)) + (bc < -log(bound) + c(0, c0)))
        tb <- 0
        
        while ((idb > 0) & (tb < 30)) {
            t <- t * 0.5
            bc <- nb + t * po
            idb <- sum((bc > log(bound) + c(0, c0)) + (bc < -log(bound) + c(0, 
                c0)))
        }
        
        con2 <- s == 0
        con3 <- abs((s/of - 1) * 1e+08) < 1
        
        if (con2 | con3) 
            break
        
        nb <- bc
        s_ob <- of
        s_nb <- s
        of <- s
        cn <- cn + 1
    }
    
    if (s_ob > s_nb) 
        best <- as.numeric(nb)
    if (s_ob <= s_nb) 
        best <- as.numeric(ob)
    
    return(best)
}



