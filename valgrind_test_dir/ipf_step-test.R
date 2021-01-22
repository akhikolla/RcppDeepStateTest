function (w, classes, targets) 
{
    e <- get("data.env", .GlobalEnv)
    e[["ipf_step"]][[length(e[["ipf_step"]]) + 1]] <- list(w = w, 
        classes = classes, targets = targets)
    .Call("_surveysd_ipf_step", PACKAGE = "surveysd", w, classes, 
        targets)
}
