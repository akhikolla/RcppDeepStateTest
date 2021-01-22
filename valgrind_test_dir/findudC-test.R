function (x) 
{
    e <- get("data.env", .GlobalEnv)
    e[["findudC"]][[length(e[["findudC"]]) + 1]] <- list(x = x)
    .Call("_remote_findudC", PACKAGE = "remote", x)
}
