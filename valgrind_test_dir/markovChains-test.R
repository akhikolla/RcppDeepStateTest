function (nchains, P, chainLen, state0) 
{
    e <- get("data.env", .GlobalEnv)
    e[["markovChains"]][[length(e[["markovChains"]]) + 1]] <- list(nchains = nchains, 
        P = P, chainLen = chainLen, state0 = state0)
    .Call("_simstudy_markovChains", nchains, P, chainLen, state0)
}
