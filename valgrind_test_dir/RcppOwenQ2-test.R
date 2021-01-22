function (nu, t, delta, R, algo = 1L) 
{
    e <- get("data.env", .GlobalEnv)
    e[["RcppOwenQ2"]][[length(e[["RcppOwenQ2"]]) + 1]] <- list(nu = nu, 
        t = t, delta = delta, R = R, algo = algo)
    .Call("_OwenQ_RcppOwenQ2", PACKAGE = "OwenQ", nu, t, delta, 
        R, algo)
}
