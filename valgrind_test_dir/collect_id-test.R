function (dn) 
{
    e <- get("data.env", .GlobalEnv)
    e[["collect_id"]][[length(e[["collect_id"]]) + 1]] <- list(dn = dn)
    .Call("_ggiraph_collect_id", dn)
}
