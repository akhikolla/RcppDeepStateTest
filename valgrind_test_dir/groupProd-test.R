function (v, group) 
{
    e <- get("data.env", .GlobalEnv)
    e[["groupProd"]][[length(e[["groupProd"]]) + 1]] <- list(v = v, 
        group = group)
    .Call("_PanelCount_groupProd", PACKAGE = "PanelCount", v, 
        group)
}
