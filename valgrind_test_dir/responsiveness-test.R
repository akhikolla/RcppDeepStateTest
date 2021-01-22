function (dvs, v, nd, bandwidth = 0.01) 
{
    e <- get("data.env", .GlobalEnv)
    e[["responsiveness"]][[length(e[["responsiveness"]]) + 1]] <- list(dvs = dvs, 
        v = v, nd = nd, bandwidth = bandwidth)
    .Call("_redist_responsiveness", dvs, v, nd, bandwidth)
}
