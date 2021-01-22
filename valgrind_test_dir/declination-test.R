function (dvs, dseat_vec, nd) 
{
    e <- get("data.env", .GlobalEnv)
    e[["declination"]][[length(e[["declination"]]) + 1]] <- list(dvs = dvs, 
        dseat_vec = dseat_vec, nd = nd)
    .Call("_redist_declination", dvs, dseat_vec, nd)
}
