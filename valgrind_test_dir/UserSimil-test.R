function (x, damp) 
{
    e <- get("data.env", .GlobalEnv)
    e[["UserSimil"]][[length(e[["UserSimil"]]) + 1]] <- list(x = x, 
        damp = damp)
    .Call("_rrecsys_UserSimil", PACKAGE = "rrecsys", x, damp)
}
