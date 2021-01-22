function (x) 
{
    e <- get("data.env", .GlobalEnv)
    e[["Tab"]][[length(e[["Tab"]]) + 1]] <- list(x = x)
    .Call("_diveRsity_Tab", x)
}
