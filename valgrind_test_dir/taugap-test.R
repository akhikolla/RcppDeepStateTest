function (tau, dvs, dseat_vec, nd) 
{
    e <- get("data.env", .GlobalEnv)
    e[["taugap"]][[length(e[["taugap"]]) + 1]] <- list(tau = tau, 
        dvs = dvs, dseat_vec = dseat_vec, nd = nd)
    .Call("_redist_taugap", tau, dvs, dseat_vec, nd)
}
