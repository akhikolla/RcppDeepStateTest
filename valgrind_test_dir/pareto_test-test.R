function (dat) 
{
    e <- get("data.env", .GlobalEnv)
    e[["pareto_test"]][[length(e[["pareto_test"]]) + 1]] <- list(dat = dat)
    .Call("_ptsuite_pareto_test", PACKAGE = "ptsuite", dat)
}
