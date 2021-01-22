function (S, pi, ncens, nuncens) 
{
    e <- get("data.env", .GlobalEnv)
    e[["lik"]][[length(e[["lik"]]) + 1]] <- list(S = S, pi = pi, 
        ncens = ncens, nuncens = nuncens)
    .Call("_DStree_lik", PACKAGE = "DStree", S, pi, ncens, nuncens)
}
