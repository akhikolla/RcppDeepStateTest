function (w, classes, targets) 
{
    e <- get("data.env", .GlobalEnv)
    e[["ipf_step_ref"]][[length(e[["ipf_step_ref"]]) + 1]] <- list(w = w, 
        classes = classes, targets = targets)
    invisible(c(".Call", "_surveysd_ipf_step_ref", "surveysd", 
    "w", "classes", "targets"))
}
