function (truth, times, unique_times, FX_train, FX_predict, lambda) 
{
    e <- get("data.env", .GlobalEnv)
    e[["C_Akritas"]][[length(e[["C_Akritas"]]) + 1]] <- list(truth = truth, 
        times = times, unique_times = unique_times, FX_train = FX_train, 
        FX_predict = FX_predict, lambda = lambda)
    .Call("_survivalmodels_C_Akritas", truth, times, unique_times, 
        FX_train, FX_predict, lambda)
}
