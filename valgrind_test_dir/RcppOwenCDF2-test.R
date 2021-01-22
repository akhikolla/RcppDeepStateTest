function (nu, t1, t2, delta1, delta2, algo = 1L) 
{
    e <- get("data.env", .GlobalEnv)
    e[["RcppOwenCDF2"]][[length(e[["RcppOwenCDF2"]]) + 1]] <- list(nu = nu, 
        t1 = t1, t2 = t2, delta1 = delta1, delta2 = delta2, algo = algo)
    .Call("_OwenQ_RcppOwenCDF2", PACKAGE = "OwenQ", nu, t1, t2, 
        delta1, delta2, algo)
}
