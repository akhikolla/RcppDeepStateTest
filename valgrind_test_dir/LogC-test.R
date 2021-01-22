function (fai) 
{
    e <- get("data.env", .GlobalEnv)
    e[["LogC"]][[length(e[["LogC"]]) + 1]] <- list(fai = fai)
    .Call("_rankdist_LogC", fai)
}
