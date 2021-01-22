function (ni_, n_j) 
{
    e <- get("data.env", .GlobalEnv)
    e[["expected_MI"]][[length(e[["expected_MI"]]) + 1]] <- list(ni_ = ni_, 
        n_j = n_j)
    .Call("_aricode_expected_MI", PACKAGE = "aricode", ni_, n_j)
}
