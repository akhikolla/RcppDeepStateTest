function (theta_index, irfprob, dim_irfprob) 
{
    e <- get("data.env", .GlobalEnv)
    e[["cdm_rcpp_sim_model_item_responses"]][[length(e[["cdm_rcpp_sim_model_item_responses"]]) + 
        1]] <- list(theta_index = theta_index, irfprob = irfprob, 
        dim_irfprob = dim_irfprob)
    .Call("_CDM_cdm_rcpp_sim_model_item_responses", PACKAGE = "CDM", 
        theta_index, irfprob, dim_irfprob)
}
