function (x, lb, ub) 
{
    e <- get("data.env", .GlobalEnv)
    e[["anti_transformation"]][[length(e[["anti_transformation"]]) + 
        1]] <- list(x = x, lb = lb, ub = ub)
    .Call("_RMPSH_anti_transformation", x, lb, ub)
}
