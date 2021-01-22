function (dvs, dseat_vec, nd) 
{
    e <- get("data.env", .GlobalEnv)
    e[["effgapEP"]][[length(e[["effgapEP"]]) + 1]] <- list(dvs = dvs, 
        dseat_vec = dseat_vec, nd = nd)
    .Call("_redist_effgapEP", dvs, dseat_vec, nd)
}
