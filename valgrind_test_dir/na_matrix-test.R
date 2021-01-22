function (n) 
{
    e <- get("data.env", .GlobalEnv)
    e[["na_matrix"]][[length(e[["na_matrix"]]) + 1]] <- list(n = n)
    .Call("_dpseg_na_matrix", PACKAGE = "dpseg", n)
}
