function (nu, t, delta, R, algo = 1L) 
{
    e <- get("data.env", .GlobalEnv)
    e[["RcppOwenQ1"]][[length(e[["RcppOwenQ1"]]) + 1]] <- list(nu = nu, 
        t = t, delta = delta, R = R, algo = algo)
    .Call("_OwenQ_RcppOwenQ1", PACKAGE = "OwenQ", nu, t, delta, 
        R, algo)
}
