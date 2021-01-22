function (data, L) 
{
    e <- get("data.env", .GlobalEnv)
    e[["screened_poisson_dct"]][[length(e[["screened_poisson_dct"]]) + 
        1]] <- list(data = data, L = L)
    .Call("_imagerExtra_screened_poisson_dct", data, L)
}
