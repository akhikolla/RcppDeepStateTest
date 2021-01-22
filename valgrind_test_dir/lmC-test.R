function (x, y) 
{
    e <- get("data.env", .GlobalEnv)
    e[["lmC"]][[length(e[["lmC"]]) + 1]] <- list(x = x, y = y)
    .Call("_remote_lmC", PACKAGE = "remote", x, y)
}
