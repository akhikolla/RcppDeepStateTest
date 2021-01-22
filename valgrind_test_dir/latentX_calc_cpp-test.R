function (parAlpha, epsilonT, ndays) 
{
    e <- get("data.env", .GlobalEnv)
    e[["latentX_calc_cpp"]][[length(e[["latentX_calc_cpp"]]) + 
        1]] <- list(parAlpha = parAlpha, epsilonT = epsilonT, 
        ndays = ndays)
    .Call("_foreSIGHT_latentX_calc_cpp", parAlpha, epsilonT, 
        ndays)
}
