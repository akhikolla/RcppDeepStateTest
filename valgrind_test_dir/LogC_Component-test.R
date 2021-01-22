function (fai) 
{
    e <- get("data.env", .GlobalEnv)
    e[["LogC_Component"]][[length(e[["LogC_Component"]]) + 1]] <- list(fai = fai)
    .Call("_rankdist_LogC_Component", fai)
}
