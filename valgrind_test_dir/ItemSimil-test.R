function (x, DAMP) 
{
    e <- get("data.env", .GlobalEnv)
    e[["ItemSimil"]][[length(e[["ItemSimil"]]) + 1]] <- list(x = x, 
        DAMP = DAMP)
    .Call("_rrecsys_ItemSimil", PACKAGE = "rrecsys", x, DAMP)
}
