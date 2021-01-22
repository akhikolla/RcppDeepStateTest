function (nobj) 
{
    e <- get("data.env", .GlobalEnv)
    e[["AllPerms"]][[length(e[["AllPerms"]]) + 1]] <- list(nobj = nobj)
    .Call("_rankdist_AllPerms", nobj)
}
