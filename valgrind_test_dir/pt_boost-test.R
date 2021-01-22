function (q, nu, delta) 
{
    e <- get("data.env", .GlobalEnv)
    e[["pt_boost"]][[length(e[["pt_boost"]]) + 1]] <- list(q = q, 
        nu = nu, delta = delta)
    .Call("_OwenQ_pt_boost", PACKAGE = "OwenQ", q, nu, delta)
}
