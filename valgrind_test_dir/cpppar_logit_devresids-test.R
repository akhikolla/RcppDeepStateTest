function (y, mu, wt, nthreads) 
{
    e <- get("data.env", .GlobalEnv)
    e[["cpppar_logit_devresids"]][[length(e[["cpppar_logit_devresids"]]) + 
        1]] <- list(y = y, mu = mu, wt = wt, nthreads = nthreads)
    .Call("_fixest_cpppar_logit_devresids", y, mu, wt, nthreads)
}
