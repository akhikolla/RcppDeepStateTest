function (x, sub) 
{
    e <- get("data.env", .GlobalEnv)
    e[["C_subsetMin"]][[length(e[["C_subsetMin"]]) + 1]] <- list(x = x, 
        sub = sub)
    .Call("_cna_C_subsetMin", x, sub)
}
