function (a1, b, resids, n) 
{
    e <- get("data.env", .GlobalEnv)
    e[["update_sigma"]][[length(e[["update_sigma"]]) + 1]] <- list(a1 = a1, 
        b = b, resids = resids, n = n)
    .Call("_bartBMA_update_sigma", a1, b, resids, n)
}
