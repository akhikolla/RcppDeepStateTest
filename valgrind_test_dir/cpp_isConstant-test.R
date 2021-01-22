function (x) 
{
    e <- get("data.env", .GlobalEnv)
    e[["cpp_isConstant"]][[length(e[["cpp_isConstant"]]) + 1]] <- list(x = x)
    .Call("_fixest_cpp_isConstant", x)
}
