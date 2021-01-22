function (post, est, max_est_index, N, prob_theta, eps) 
{
    e <- get("data.env", .GlobalEnv)
    e[["cdm_rcpp_est_calc_accuracy_version2_consistency_helper"]][[length(e[["cdm_rcpp_est_calc_accuracy_version2_consistency_helper"]]) + 
        1]] <- list(post = post, est = est, max_est_index = max_est_index, 
        N = N, prob_theta = prob_theta, eps = eps)
    .Call("_CDM_cdm_rcpp_est_calc_accuracy_version2_consistency_helper", 
        PACKAGE = "CDM", post, est, max_est_index, N, prob_theta, 
        eps)
}
