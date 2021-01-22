function (prob, Xspread, Xbal) 
{
    e <- get("data.env", .GlobalEnv)
    e[["lcube"]][[length(e[["lcube"]]) + 1]] <- list(prob = prob, 
        Xspread = Xspread, Xbal = Xbal)
    .Call("_BalancedSampling_lcube", PACKAGE = "BalancedSampling", 
        prob, Xspread, Xbal)
}
