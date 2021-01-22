function (r, n, ex, tx) 
{
    e <- get("data.env", .GlobalEnv)
    e[["g_weib"]][[length(e[["g_weib"]]) + 1]] <- list(r = r, 
        n = n, ex = ex, tx = tx)
    .Call("_mixR_g_weib", r, n, ex, tx)
}
