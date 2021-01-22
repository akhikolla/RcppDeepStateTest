function (x) 
{
    e <- get("data.env", .GlobalEnv)
    e[["cpp_pgcd"]][[length(e[["cpp_pgcd"]]) + 1]] <- list(x = x)
    .Call("_fixest_cpp_pgcd", x)
}
