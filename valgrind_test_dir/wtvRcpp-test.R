function (x, w) 
{
    e <- get("data.env", .GlobalEnv)
    e[["wtvRcpp"]][[length(e[["wtvRcpp"]]) + 1]] <- list(x = x, 
        w = w)
    .Call("_propr_wtvRcpp", x, w)
}
