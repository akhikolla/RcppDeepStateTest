function (x) 
{
    e <- get("data.env", .GlobalEnv)
    e[["is_ordered_numeric"]][[length(e[["is_ordered_numeric"]]) + 
        1]] <- list(x = x)
    .Call("_tibbletime_is_ordered_numeric", x)
}
