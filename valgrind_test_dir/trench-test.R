function (r, y, N) 
{
    e <- get("data.env", .GlobalEnv)
    e[["trench"]][[length(e[["trench"]]) + 1]] <- list(r = r, 
        y = y, N = N)
    .Call("_FastGP_trench", PACKAGE = "FastGP", r, y, N)
}
