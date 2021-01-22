function (af) 
{
    e <- get("data.env", .GlobalEnv)
    e[["expHet"]][[length(e[["expHet"]]) + 1]] <- list(af = af)
    .Call("_diveRsity_expHet", af)
}
