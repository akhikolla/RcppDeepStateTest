function (x) 
{
    e <- get("data.env", .GlobalEnv)
    e[["any_naC"]][[length(e[["any_naC"]]) + 1]] <- list(x = x)
    .Call("_phylobase_any_naC", x)
}
