function (im, Mu, Nu, Lambda1, Lambda2, tol, maxiter, dt, phi) 
{
    e <- get("data.env", .GlobalEnv)
    e[["ChanVese"]][[length(e[["ChanVese"]]) + 1]] <- list(im = im, 
        Mu = Mu, Nu = Nu, Lambda1 = Lambda1, Lambda2 = Lambda2, 
        tol = tol, maxiter = maxiter, dt = dt, phi = phi)
    .Call("_imagerExtra_ChanVese", im, Mu, Nu, Lambda1, Lambda2, 
        tol, maxiter, dt, phi)
}
