function (X, nsites, p, beta, offset) 
{
    e <- get("data.env", .GlobalEnv)
    e[["linpredcompute"]][[length(e[["linpredcompute"]]) + 1]] <- list(X = X, 
        nsites = nsites, p = p, beta = beta, offset = offset)
    .Call("_CARBayes_linpredcompute", X, nsites, p, beta, offset)
}
