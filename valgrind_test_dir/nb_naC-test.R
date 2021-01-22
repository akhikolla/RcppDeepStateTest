function (x) 
{
    e <- get("data.env", .GlobalEnv)
    e[["nb_naC"]][[length(e[["nb_naC"]]) + 1]] <- list(x = x)
    .Call("_phylobase_nb_naC", x)
}
