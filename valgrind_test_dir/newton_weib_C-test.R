function (n, ex, tx, r = 1, max_iter = 100L) 
{
    e <- get("data.env", .GlobalEnv)
    e[["newton_weib_C"]][[length(e[["newton_weib_C"]]) + 1]] <- list(n = n, 
        ex = ex, tx = tx, r = r, max_iter = max_iter)
    .Call("_mixR_newton_weib_C", n, ex, tx, r, max_iter)
}
