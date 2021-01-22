function (x) 
{
    e <- get("data.env", .GlobalEnv)
    e[["cpp_lgamma"]][[length(e[["cpp_lgamma"]]) + 1]] <- list(x = x)
    .Call("_fixest_cpp_lgamma", x)
}
