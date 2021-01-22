function (v) 
{
    e <- get("data.env", .GlobalEnv)
    e[["pFromV"]][[length(e[["pFromV"]]) + 1]] <- list(v = v)
    .Call("_bsplinePsd_pFromV", v)
}
