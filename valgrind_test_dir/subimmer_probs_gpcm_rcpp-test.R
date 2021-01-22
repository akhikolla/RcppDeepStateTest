function (x, theta, b, a, K, x_ind) 
{
    e <- get("data.env", .GlobalEnv)
    e[["subimmer_probs_gpcm_rcpp"]][[length(e[["subimmer_probs_gpcm_rcpp"]]) + 
        1]] <- list(x = x, theta = theta, b = b, a = a, K = K, 
        x_ind = x_ind)
    .Call("_immer_subimmer_probs_gpcm_rcpp", PACKAGE = "immer", 
        x, theta, b, a, K, x_ind)
}
