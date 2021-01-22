function (p, ref_order, weights, pi_inv) 
{
    e <- get("data.env", .GlobalEnv)
    e[["loglikPLMIX"]][[length(e[["loglikPLMIX"]]) + 1]] <- list(p = p, 
        ref_order = ref_order, weights = weights, pi_inv = pi_inv)
    .Call("_PLMIX_loglikPLMIX", p, ref_order, weights, pi_inv)
}
