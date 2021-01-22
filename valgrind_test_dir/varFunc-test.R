function (af, sHarm) 
{
    e <- get("data.env", .GlobalEnv)
    e[["varFunc"]][[length(e[["varFunc"]]) + 1]] <- list(af = af, 
        sHarm = sHarm)
    .Call("_diveRsity_varFunc", af, sHarm)
}
