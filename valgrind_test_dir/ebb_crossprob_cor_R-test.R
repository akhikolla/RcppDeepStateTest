function (d, bounds, correlations) 
{
    e <- get("data.env", .GlobalEnv)
    e[["ebb_crossprob_cor_R"]][[length(e[["ebb_crossprob_cor_R"]]) + 
        1]] <- list(d = d, bounds = bounds, correlations = correlations)
    .Call("_GBJ_ebb_crossprob_cor_R", PACKAGE = "GBJ", d, bounds, 
        correlations)
}
