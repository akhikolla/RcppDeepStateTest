function (K, perm, n) 
{
    e <- get("data.env", .GlobalEnv)
    e[["shuffle_grammat_rcpp"]][[length(e[["shuffle_grammat_rcpp"]]) + 
        1]] <- list(K = K, perm = perm, n = n)
    .Call("_dHSIC_shuffle_grammat_rcpp", K, perm, n)
}
