function (x, nthreads) 
{
    e <- get("data.env", .GlobalEnv)
    e[["cpppar_logit_mueta"]][[length(e[["cpppar_logit_mueta"]]) + 
        1]] <- list(x = x, nthreads = nthreads)
    .Call("_fixest_cpppar_logit_mueta", x, nthreads)
}
