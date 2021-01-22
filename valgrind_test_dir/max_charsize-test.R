function (x) 
{
    e <- get("data.env", .GlobalEnv)
    e[["max_charsize"]][[length(e[["max_charsize"]]) + 1]] <- list(x = x)
    .Call("_hutilscpp_max_charsize", x)
}
