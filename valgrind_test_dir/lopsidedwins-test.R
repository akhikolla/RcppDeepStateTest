function (dvs, dseat_vec, nd) 
{
    e <- get("data.env", .GlobalEnv)
    e[["lopsidedwins"]][[length(e[["lopsidedwins"]]) + 1]] <- list(dvs = dvs, 
        dseat_vec = dseat_vec, nd = nd)
    .Call("_redist_lopsidedwins", dvs, dseat_vec, nd)
}
