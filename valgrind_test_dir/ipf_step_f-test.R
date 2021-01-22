function (w, classes, targets) 
{
    e <- get("data.env", .GlobalEnv)
    e[["ipf_step_f"]][[length(e[["ipf_step_f"]]) + 1]] <- list(w = w, 
        classes = classes, targets = targets)
    .Call("_surveysd_ipf_step_f", PACKAGE = "surveysd", w, classes, 
        targets)
}
