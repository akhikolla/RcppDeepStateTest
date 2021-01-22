function (x) 
{
    e <- get("data.env", .GlobalEnv)
    e[["timesTwo"]][[length(e[["timesTwo"]]) + 1]] <- list(x = x)
    .Call("_CENFA_timesTwo", PACKAGE = "CENFA", x)
}
