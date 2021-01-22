function (x) 
{
    e <- get("data.env", .GlobalEnv)
    e[["na_locf_numeric"]][[length(e[["na_locf_numeric"]]) + 
        1]] <- list(x = x)
    .Call("_QuantTools_na_locf_numeric", x)
}
