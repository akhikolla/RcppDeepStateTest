function (x, y) 
{
    e <- get("data.env", .GlobalEnv)
    e[["empirical_mi"]][[length(e[["empirical_mi"]]) + 1]] <- list(x = x, 
        y = y)
    .Call("_BNSL_empirical_mi", x, y)
}
