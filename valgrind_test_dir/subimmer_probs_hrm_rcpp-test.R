function (x, xi, phi, psi, K, x_ind) 
{
    e <- get("data.env", .GlobalEnv)
    e[["subimmer_probs_hrm_rcpp"]][[length(e[["subimmer_probs_hrm_rcpp"]]) + 
        1]] <- list(x = x, xi = xi, phi = phi, psi = psi, K = K, 
        x_ind = x_ind)
    .Call("_immer_subimmer_probs_hrm_rcpp", PACKAGE = "immer", 
        x, xi, phi, psi, K, x_ind)
}
