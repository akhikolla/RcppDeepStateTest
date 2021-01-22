function (p, nu, delta) 
{
    e <- get("data.env", .GlobalEnv)
    e[["qt_boost"]][[length(e[["qt_boost"]]) + 1]] <- list(p = p, 
        nu = nu, delta = delta)
    .Call("_OwenQ_qt_boost", PACKAGE = "OwenQ", p, nu, delta)
}
