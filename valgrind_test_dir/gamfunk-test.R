function (epsmat, gammat) 
{
    e <- get("data.env", .GlobalEnv)
    e[["gamfunk"]][[length(e[["gamfunk"]]) + 1]] <- list(epsmat = epsmat, 
        gammat = gammat)
    .Call("_pcIRT_gamfunk", epsmat, gammat)
}
