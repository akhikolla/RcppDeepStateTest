function (y, w = numeric(0)) 
{
    e <- get("data.env", .GlobalEnv)
    e[["cpp_ssr_null"]][[length(e[["cpp_ssr_null"]]) + 1]] <- list(y = y, 
        w = w)
    .Call("_fixest_cpp_ssr_null", y, w)
}
