function (N1, N2, MTI) 
{
    e <- get("data.env", .GlobalEnv)
    e[["mpboost"]][[length(e[["mpboost"]]) + 1]] <- list(N1 = N1, 
        N2 = N2, MTI = MTI)
    .Call("_MPBoost_mpboost", N1, N2, MTI)
}
