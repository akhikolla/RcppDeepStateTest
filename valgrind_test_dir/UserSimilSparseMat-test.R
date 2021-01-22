function (x, dim, damp) 
{
    e <- get("data.env", .GlobalEnv)
    e[["UserSimilSparseMat"]][[length(e[["UserSimilSparseMat"]]) + 
        1]] <- list(x = x, dim = dim, damp = damp)
    .Call("_rrecsys_UserSimilSparseMat", PACKAGE = "rrecsys", 
        x, dim, damp)
}
