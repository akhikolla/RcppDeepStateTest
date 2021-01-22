function (score, truth, unique_times, cens) 
{
    e <- get("data.env", .GlobalEnv)
    e[["c_weight_survival_score"]][[length(e[["c_weight_survival_score"]]) + 
        1]] <- list(score = score, truth = truth, unique_times = unique_times, 
        cens = cens)
    .Call("_mlr3proba_c_weight_survival_score", PACKAGE = "mlr3proba", 
        score, truth, unique_times, cens)
}
