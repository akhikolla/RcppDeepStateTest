function (value) 
{
    e <- get("data.env", .GlobalEnv)
    e[["get_chisq1_percentile"]][[length(e[["get_chisq1_percentile"]]) + 
        1]] <- list(value = value)
    .Call("_finity_get_chisq1_percentile", value)
}
