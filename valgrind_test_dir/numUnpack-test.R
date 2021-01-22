function (pack) 
{
    e <- get("data.env", .GlobalEnv)
    e[["numUnpack"]][[length(e[["numUnpack"]]) + 1]] <- list(pack = pack)
    .Call("_GGIR_numUnpack", pack)
}
