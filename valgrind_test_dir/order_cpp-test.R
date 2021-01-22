function () 
{
    e <- get("data.env", .GlobalEnv)
    e[["order_cpp"]][[length(e[["order_cpp"]]) + 1]] <- list()
    list(NULL, character(0))
}
