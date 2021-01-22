function (x, dim, DAMP) 
{
    e <- get("data.env", .GlobalEnv)
    e[["ItemSimilSparseMat"]][[length(e[["ItemSimilSparseMat"]]) + 
        1]] <- list(x = x, dim = dim, DAMP = DAMP)
    .Call("_rrecsys_ItemSimilSparseMat", PACKAGE = "rrecsys", 
        x, dim, DAMP)
}
