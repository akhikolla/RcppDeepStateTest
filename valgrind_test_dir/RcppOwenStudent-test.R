function (q, nu, delta) 
{
    e <- get("data.env", .GlobalEnv)
    e[["RcppOwenStudent"]][[length(e[["RcppOwenStudent"]]) + 
        1]] <- list(q = q, nu = nu, delta = delta)
    .Call("_OwenQ_RcppOwenStudent", PACKAGE = "OwenQ", q, nu, 
        delta)
}
