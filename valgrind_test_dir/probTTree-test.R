function (ttree, rOff, pOff, pi, shGen, scGen, shSam, scSam, 
    dateT, delta_t = 0.01) 
{
    e <- get("data.env", .GlobalEnv)
    e[["probTTree"]][[length(e[["probTTree"]]) + 1]] <- list(ttree = ttree, 
        rOff = rOff, pOff = pOff, pi = pi, shGen = shGen, scGen = scGen, 
        shSam = shSam, scSam = scSam, dateT = dateT, delta_t = delta_t)
    .Call("_TransPhylo_probTTree", PACKAGE = "TransPhylo", ttree, 
        rOff, pOff, pi, shGen, scGen, shSam, scSam, dateT, delta_t)
}
