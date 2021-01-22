function (id, nsub) 
{
    e <- get("data.env", .GlobalEnv)
    e[["getrids"]][[length(e[["getrids"]]) + 1]] <- list(id = id, 
        nsub = nsub)
    .Call("_icensmis_getrids", PACKAGE = "icensmis", id, nsub)
}
