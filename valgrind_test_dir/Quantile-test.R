function (x, probs) 
{
    e <- get("data.env", .GlobalEnv)
    e[["Quantile"]][[length(e[["Quantile"]]) + 1]] <- list(x = x, 
        probs = probs)
    .Call("_bartBMA_Quantile", x, probs)
}
