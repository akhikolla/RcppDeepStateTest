function (x, l) 
{
    e <- get("data.env", .GlobalEnv)
    e[["C_relist_Int"]][[length(e[["C_relist_Int"]]) + 1]] <- list(x = x, 
        l = l)
    .Call("_cna_C_relist_Int", x, l)
}
