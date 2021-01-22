function (ID, data, lenBloom, t) 
{
    e <- get("data.env", .GlobalEnv)
    e[["WolframRule30"]][[length(e[["WolframRule30"]]) + 1]] <- list(ID = ID, 
        data = data, lenBloom = lenBloom, t = t)
    .Call("_PPRL_WolframRule30", PACKAGE = "PPRL", ID, data, 
        lenBloom, t)
}
