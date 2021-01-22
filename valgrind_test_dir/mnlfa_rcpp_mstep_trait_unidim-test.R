function (theta, mu_p, sigma_p, post) 
{
    e <- get("data.env", .GlobalEnv)
    e[["mnlfa_rcpp_mstep_trait_unidim"]][[length(e[["mnlfa_rcpp_mstep_trait_unidim"]]) + 
        1]] <- list(theta = theta, mu_p = mu_p, sigma_p = sigma_p, 
        post = post)
    .Call("_mnlfa_mnlfa_rcpp_mstep_trait_unidim", PACKAGE = "mnlfa", 
        theta, mu_p, sigma_p, post)
}
