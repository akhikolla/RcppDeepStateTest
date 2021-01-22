function (px, py, m, T_observed, accuracy = 1e-05) 
{
    e <- get("data.env", .GlobalEnv)
    e[["jaccard_mca_rcpp"]][[length(e[["jaccard_mca_rcpp"]]) + 
        1]] <- list(px = px, py = py, m = m, T_observed = T_observed, 
        accuracy = accuracy)
    .Call("_jaccard_jaccard_mca_rcpp", PACKAGE = "jaccard", px, 
        py, m, T_observed, accuracy)
}
