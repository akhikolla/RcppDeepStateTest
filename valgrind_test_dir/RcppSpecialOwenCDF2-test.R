function (nu, t, delta, algo = 1L) 
{
    e <- get("data.env", .GlobalEnv)
    e[["RcppSpecialOwenCDF2"]][[length(e[["RcppSpecialOwenCDF2"]]) + 
        1]] <- list(nu = nu, t = t, delta = delta, algo = algo)
    .Call("_OwenQ_RcppSpecialOwenCDF2", PACKAGE = "OwenQ", nu, 
        t, delta, algo)
}
