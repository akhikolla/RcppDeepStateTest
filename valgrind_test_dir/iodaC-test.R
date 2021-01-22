function (x, y) 
{
    e <- get("data.env", .GlobalEnv)
    e[["iodaC"]][[length(e[["iodaC"]]) + 1]] <- list(x = x, y = y)
    .Call("_remote_iodaC", PACKAGE = "remote", x, y)
}
