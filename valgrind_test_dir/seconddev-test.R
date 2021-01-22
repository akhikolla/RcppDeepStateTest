function (g, y, w, n, group, theta) 
{
    e <- get("data.env", .GlobalEnv)
    e[["seconddev"]][[length(e[["seconddev"]]) + 1]] <- list(g = g, 
        y = y, w = w, n = n, group = group, theta = theta)
    .Call("_clogitboost_seconddev", PACKAGE = "clogitboost", 
        g, y, w, n, group, theta)
}
