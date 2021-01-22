function (x, w) 
{
    e <- get("data.env", .GlobalEnv)
    e[["wtmRcpp"]][[length(e[["wtmRcpp"]]) + 1]] <- list(x = x, 
        w = w)
    .Call("_propr_wtmRcpp", x, w)
}
