function (u, l, r) 
{
    e <- get("data.env", .GlobalEnv)
    e[["fun_sublr"]][[length(e[["fun_sublr"]]) + 1]] <- list(u = u, 
        l = l, r = r)
    .Call("_ALassoSurvIC_fun_sublr", PACKAGE = "ALassoSurvIC", 
        u, l, r)
}
