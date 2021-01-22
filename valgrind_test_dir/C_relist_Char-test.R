function (x, l) 
{
    e <- get("data.env", .GlobalEnv)
    e[["C_relist_Char"]][[length(e[["C_relist_Char"]]) + 1]] <- list(x = x, 
        l = l)
    .Call("_cna_C_relist_Char", x, l)
}
