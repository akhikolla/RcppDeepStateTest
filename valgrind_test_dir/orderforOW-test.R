function (x) 
{
    e <- get("data.env", .GlobalEnv)
    e[["orderforOW"]][[length(e[["orderforOW"]]) + 1]] <- list(x = x)
    .Call("_bartBMA_orderforOW", x)
}
