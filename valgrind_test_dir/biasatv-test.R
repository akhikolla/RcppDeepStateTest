function (dvs, v, nd) 
{
    e <- get("data.env", .GlobalEnv)
    e[["biasatv"]][[length(e[["biasatv"]]) + 1]] <- list(dvs = dvs, 
        v = v, nd = nd)
    .Call("_redist_biasatv", dvs, v, nd)
}
