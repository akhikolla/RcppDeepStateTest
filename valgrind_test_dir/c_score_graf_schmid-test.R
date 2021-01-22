function (truth, unique_times, cdf, power = 2L) 
{
    e <- get("data.env", .GlobalEnv)
    e[["c_score_graf_schmid"]][[length(e[["c_score_graf_schmid"]]) + 
        1]] <- list(truth = truth, unique_times = unique_times, 
        cdf = cdf, power = power)
    .Call("_mlr3proba_c_score_graf_schmid", PACKAGE = "mlr3proba", 
        truth, unique_times, cdf, power)
}
