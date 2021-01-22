function (x, K = 4L, num_init = 10L) 
{
    e <- get("data.env", .GlobalEnv)
    e[["OrderKmeansCpp"]][[length(e[["OrderKmeansCpp"]]) + 1]] <- list(x = x, 
        K = K, num_init = num_init)
    .Call("_offlineChange_OrderKmeansCpp", PACKAGE = "offlineChange", 
        x, K, num_init)
}
