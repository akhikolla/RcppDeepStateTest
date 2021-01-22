function (x, x2, n) 
{
    e <- get("data.env", .GlobalEnv)
    e[["mll_meanvar2"]][[length(e[["mll_meanvar2"]]) + 1]] <- list(x = x, 
        x2 = x2, n = n)
    .Call("_bartBMA_mll_meanvar2", x, x2, n)
}
