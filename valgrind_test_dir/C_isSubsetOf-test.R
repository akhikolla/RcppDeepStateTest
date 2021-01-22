function (x, y) 
{
    e <- get("data.env", .GlobalEnv)
    e[["C_isSubsetOf"]][[length(e[["C_isSubsetOf"]]) + 1]] <- list(x = x, 
        y = y)
    .Call("_cna_C_isSubsetOf", x, y)
}
