function (K) 
{
    e <- get("data.env", .GlobalEnv)
    e[["alpha2"]][[length(e[["alpha2"]]) + 1]] <- list(K = K)
    .Call("_GDINA_alpha2", PACKAGE = "GDINA", K)
}
