function (n, size, prob) 
{
    e <- get("data.env", .GlobalEnv)
    e[["quickintsample"]][[length(e[["quickintsample"]]) + 1]] <- list(n = n, 
        size = size, prob = prob)
    .Call("_PLMIX_quickintsample", n, size, prob)
}
