function (x, n, d) 
{
    e <- get("data.env", .GlobalEnv)
    e[["discrete_grammat_rcpp"]][[length(e[["discrete_grammat_rcpp"]]) + 
        1]] <- list(x = x, n = n, d = d)
    .Call("_dHSIC_discrete_grammat_rcpp", x, n, d)
}
