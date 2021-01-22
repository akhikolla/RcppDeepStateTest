function (u, lessthan) 
{
    e <- get("data.env", .GlobalEnv)
    e[["fun_subless"]][[length(e[["fun_subless"]]) + 1]] <- list(u = u, 
        lessthan = lessthan)
    .Call("_ALassoSurvIC_fun_subless", PACKAGE = "ALassoSurvIC", 
        u, lessthan)
}
