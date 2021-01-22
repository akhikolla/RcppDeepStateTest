function (x) 
{
    e <- get("data.env", .GlobalEnv)
    e[["order_intvec_"]][[length(e[["order_intvec_"]]) + 1]] <- list(x = x)
    .Call("_bartBMA_order_intvec_", x)
}
