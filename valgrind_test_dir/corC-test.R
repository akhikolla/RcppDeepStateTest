function (x, y) 
{
    e <- get("data.env", .GlobalEnv)
    e[["corC"]][[length(e[["corC"]]) + 1]] <- list(x = x, y = y)
    .Call("_remote_corC", PACKAGE = "remote", x, y)
}
