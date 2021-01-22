function (x) 
{
    e <- get("data.env", .GlobalEnv)
    e[["cpp_unclassFactor"]][[length(e[["cpp_unclassFactor"]]) + 
        1]] <- list(x = x)
    .Call("_FENmlm_cpp_unclassFactor", x)
}
