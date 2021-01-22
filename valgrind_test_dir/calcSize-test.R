function (col, fam) 
{
    e <- get("data.env", .GlobalEnv)
    e[["calcSize"]][[length(e[["calcSize"]]) + 1]] <- list(col = col, 
        fam = fam)
    .Call("_NAM_calcSize", col, fam)
}
