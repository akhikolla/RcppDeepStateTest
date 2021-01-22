function (n, k) 
{
    e <- get("data.env", .GlobalEnv)
    e[["combnCpp"]][[length(e[["combnCpp"]]) + 1]] <- list(n = n, 
        k = k)
    .Call("_GDINA_combnCpp", PACKAGE = "GDINA", n, k)
}
