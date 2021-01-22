function (ID, data, lenBloom, t) 
{
    e <- get("data.env", .GlobalEnv)
    e[["WolframRule90"]][[length(e[["WolframRule90"]]) + 1]] <- list(ID = ID, 
        data = data, lenBloom = lenBloom, t = t)
    .Call("_PPRL_WolframRule90", PACKAGE = "PPRL", ID, data, 
        lenBloom, t)
}
