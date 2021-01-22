function (X, P, H, t, N) 
{
    e <- get("data.env", .GlobalEnv)
    e[["predCoef"]][[length(e[["predCoef"]]) + 1]] <- list(X = X, 
        P = P, H = H, t = t, N = N)
    .Call("_forecastSNSTS_predCoef", PACKAGE = "forecastSNSTS", 
        X, P, H, t, N)
}
