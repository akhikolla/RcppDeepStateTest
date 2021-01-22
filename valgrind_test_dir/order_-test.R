function (x) 
{
    e <- get("data.env", .GlobalEnv)
    e[["order_"]][[length(e[["order_"]]) + 1]] <- list(x = x)
    .Call("_flam_order_", PACKAGE = "flam", x)
}
