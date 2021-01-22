function (x, l, r) 
{
    e <- get("data.env", .GlobalEnv)
    e[["mean_help"]][[length(e[["mean_help"]]) + 1]] <- list(x = x, 
        l = l, r = r)
    .Call("_mosum_mean_help", x, l, r)
}
