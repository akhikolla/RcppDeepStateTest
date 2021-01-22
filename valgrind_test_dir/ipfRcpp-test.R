function (aj1T, base, eps) 
{
    e <- get("data.env", .GlobalEnv)
    e[["ipfRcpp"]][[length(e[["ipfRcpp"]]) + 1]] <- list(aj1T = aj1T, 
        base = base, eps = eps)
    .Call("_equateMultiple_ipfRcpp", aj1T, base, eps)
}
