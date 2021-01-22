function (true_times, req_times) 
{
    e <- get("data.env", .GlobalEnv)
    e[["c_get_unique_times"]][[length(e[["c_get_unique_times"]]) + 
        1]] <- list(true_times = true_times, req_times = req_times)
    .Call("_mlr3proba_c_get_unique_times", PACKAGE = "mlr3proba", 
        true_times, req_times)
}
