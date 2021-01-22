function (x, nthreads) 
{
    e <- get("data.env", .GlobalEnv)
    e[["cpppar_logit_linkinv"]][[length(e[["cpppar_logit_linkinv"]]) + 
        1]] <- list(x = x, nthreads = nthreads)
    .Call("_fixest_cpppar_logit_linkinv", x, nthreads)
}
