function (x) 
{
    e <- get("data.env", .GlobalEnv)
    e[["all_naC"]][[length(e[["all_naC"]]) + 1]] <- list(x = x)
    .Call("_phylobase_all_naC", x)
}
