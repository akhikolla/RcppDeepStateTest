function (x) 
{
    e <- get("data.env", .GlobalEnv)
    e[["fun_hcross"]][[length(e[["fun_hcross"]]) + 1]] <- list(x = x)
    .Call("_ALassoSurvIC_fun_hcross", PACKAGE = "ALassoSurvIC", 
        x)
}
