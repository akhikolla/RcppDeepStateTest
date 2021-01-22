function (x, nthreads) 
{
    e <- get("data.env", .GlobalEnv)
    e[["cpppar_logit_linkfun"]][[length(e[["cpppar_logit_linkfun"]]) + 
        1]] <- list(x = x, nthreads = nthreads)
    .Call("_fixest_cpppar_logit_linkfun", x, nthreads)
}
