function (nx, ny, flavor = 0L) 
{
    e <- get("data.env", .GlobalEnv)
    e[["murakami_stat_perms"]][[length(e[["murakami_stat_perms"]]) + 
        1]] <- list(nx = nx, ny = ny, flavor = flavor)
    .Call("_BWStest_murakami_stat_perms", PACKAGE = "BWStest", 
        nx, ny, flavor)
}
