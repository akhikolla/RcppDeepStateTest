function (x, lb, ub) 
{
    e <- get("data.env", .GlobalEnv)
    e[["transformation"]][[length(e[["transformation"]]) + 1]] <- list(x = x, 
        lb = lb, ub = ub)
    .Call("_RMPSH_transformation", x, lb, ub)
}
