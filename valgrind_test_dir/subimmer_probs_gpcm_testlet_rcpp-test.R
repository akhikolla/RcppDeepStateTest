function (x, theta, u, b, a, K, x_ind) 
{
    e <- get("data.env", .GlobalEnv)
    e[["subimmer_probs_gpcm_testlet_rcpp"]][[length(e[["subimmer_probs_gpcm_testlet_rcpp"]]) + 
        1]] <- list(x = x, theta = theta, u = u, b = b, a = a, 
        K = K, x_ind = x_ind)
    .Call("_immer_subimmer_probs_gpcm_testlet_rcpp", PACKAGE = "immer", 
        x, theta, u, b, a, K, x_ind)
}
