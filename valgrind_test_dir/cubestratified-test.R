function (prob, Xbal, integerStrata) 
{
    e <- get("data.env", .GlobalEnv)
    e[["cubestratified"]][[length(e[["cubestratified"]]) + 1]] <- list(prob = prob, 
        Xbal = Xbal, integerStrata = integerStrata)
    .Call("_BalancedSampling_cubestratified", PACKAGE = "BalancedSampling", 
        prob, Xbal, integerStrata)
}
