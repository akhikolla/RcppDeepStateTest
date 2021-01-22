function (x, y, flavor = 0L) 
{
    e <- get("data.env", .GlobalEnv)
    e[["murakami_stat"]][[length(e[["murakami_stat"]]) + 1]] <- list(x = x, 
        y = y, flavor = flavor)
    .Call("_BWStest_murakami_stat", PACKAGE = "BWStest", x, y, 
        flavor)
}
