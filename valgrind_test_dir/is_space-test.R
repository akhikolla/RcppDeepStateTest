function (x) 
{
    e <- get("data.env", .GlobalEnv)
    e[["is_space"]][[length(e[["is_space"]]) + 1]] <- list(x = x)
    .Call("_hutilscpp_is_space", x)
}
