function (distmat, grouppop, fullpop) 
{
    e <- get("data.env", .GlobalEnv)
    e[["segregationcalc"]][[length(e[["segregationcalc"]]) + 
        1]] <- list(distmat = distmat, grouppop = grouppop, fullpop = fullpop)
    .Call("_redist_segregationcalc", distmat, grouppop, fullpop)
}
