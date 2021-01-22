function (tinf, dateT, rOff, pOff, pi, shGen, scGen, shSam, scSam, 
    delta_t) 
{
    e <- get("data.env", .GlobalEnv)
    e[["wbar"]][[length(e[["wbar"]]) + 1]] <- list(tinf = tinf, 
        dateT = dateT, rOff = rOff, pOff = pOff, pi = pi, shGen = shGen, 
        scGen = scGen, shSam = shSam, scSam = scSam, delta_t = delta_t)
    .Call("_TransPhylo_wbar", PACKAGE = "TransPhylo", tinf, dateT, 
        rOff, pOff, pi, shGen, scGen, shSam, scSam, delta_t)
}
