function (x) 
{
    e <- get("data.env", .GlobalEnv)
    e[["moy"]][[length(e[["moy"]]) + 1]] <- list(x = x)
    .Call("_vsgoftest_moy", PACKAGE = "vsgoftest", x)
}
