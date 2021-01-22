function (h, a) 
{
    e <- get("data.env", .GlobalEnv)
    e[["RcppOwenT"]][[length(e[["RcppOwenT"]]) + 1]] <- list(h = h, 
        a = a)
    .Call("_OwenQ_RcppOwenT", PACKAGE = "OwenQ", h, a)
}
