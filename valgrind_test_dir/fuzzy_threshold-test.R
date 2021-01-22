function (imhist, interval, n, maxiter, omegamax, omegamin, c1, 
    c2, mutrate, vmax, localsearch) 
{
    e <- get("data.env", .GlobalEnv)
    e[["fuzzy_threshold"]][[length(e[["fuzzy_threshold"]]) + 
        1]] <- list(imhist = imhist, interval = interval, n = n, 
        maxiter = maxiter, omegamax = omegamax, omegamin = omegamin, 
        c1 = c1, c2 = c2, mutrate = mutrate, vmax = vmax, localsearch = localsearch)
    .Call("_imagerExtra_fuzzy_threshold", imhist, interval, n, 
        maxiter, omegamax, omegamin, c1, c2, mutrate, vmax, localsearch)
}
