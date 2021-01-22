function (g, y, w, n, group, theta) 
{
    e <- get("data.env", .GlobalEnv)
    e[["score"]][[length(e[["score"]]) + 1]] <- list(g = g, y = y, 
        w = w, n = n, group = group, theta = theta)
    .Call("_clogitboost_score", PACKAGE = "clogitboost", g, y, 
        w, n, group, theta)
}
