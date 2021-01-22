function (idx) 
{
    e <- get("data.env", .GlobalEnv)
    e[["jaccard_coeff"]][[length(e[["jaccard_coeff"]]) + 1]] <- list(idx = idx)
    .Call("_robustSingleCell_jaccard_coeff", PACKAGE = "robustSingleCell", 
        idx)
}
