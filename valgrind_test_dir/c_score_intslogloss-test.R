function (truth, unique_times, cdf, eps) 
{
    e <- get("data.env", .GlobalEnv)
    e[["c_score_intslogloss"]][[length(e[["c_score_intslogloss"]]) + 
        1]] <- list(truth = truth, unique_times = unique_times, 
        cdf = cdf, eps = eps)
    .Call("_mlr3proba_c_score_intslogloss", PACKAGE = "mlr3proba", 
        truth, unique_times, cdf, eps)
}
