function (x) 
{
    e <- get("data.env", .GlobalEnv)
    e[["order_inc_"]][[length(e[["order_inc_"]]) + 1]] <- list(x = x)
    .Call("_bartBMA_order_inc_", x)
}
