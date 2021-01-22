function (x, y) 
{
    e <- get("data.env", .GlobalEnv)
    e[["bws_stat"]][[length(e[["bws_stat"]]) + 1]] <- list(x = x, 
        y = y)
    .Call("_BWStest_bws_stat", PACKAGE = "BWStest", x, y)
}
