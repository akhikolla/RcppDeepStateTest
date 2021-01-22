function (n, k, mu) 
{
    e <- get("data.env", .GlobalEnv)
    e[["runivm_onepar"]][[length(e[["runivm_onepar"]]) + 1]] <- list(n = n, 
        k = k, mu = mu)
    .Call("_BAMBI_runivm_onepar", n, k, mu)
}
