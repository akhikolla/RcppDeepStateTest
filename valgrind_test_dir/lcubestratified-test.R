function (prob, Xspread, Xbal, integerStrata) 
{
    e <- get("data.env", .GlobalEnv)
    e[["lcubestratified"]][[length(e[["lcubestratified"]]) + 
        1]] <- list(prob = prob, Xspread = Xspread, Xbal = Xbal, 
        integerStrata = integerStrata)
    .Call("_BalancedSampling_lcubestratified", PACKAGE = "BalancedSampling", 
        prob, Xspread, Xbal, integerStrata)
}
