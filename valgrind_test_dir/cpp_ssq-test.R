function (x, w = numeric(0)) 
{
    e <- get("data.env", .GlobalEnv)
    e[["cpp_ssq"]][[length(e[["cpp_ssq"]]) + 1]] <- list(x = x, 
        w = w)
    .Call("_fixest_cpp_ssq", x, w)
}
