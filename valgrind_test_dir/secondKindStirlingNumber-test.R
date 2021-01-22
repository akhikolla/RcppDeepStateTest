function (n, k) 
{
    e <- get("data.env", .GlobalEnv)
    e[["secondKindStirlingNumber"]][[length(e[["secondKindStirlingNumber"]]) + 
        1]] <- list(n = n, k = k)
    .Call("_bartBMA_secondKindStirlingNumber", n, k)
}
