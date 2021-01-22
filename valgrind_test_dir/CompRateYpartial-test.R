function (p, pi_inv, ref_order, z, n_rank) 
{
    e <- get("data.env", .GlobalEnv)
    e[["CompRateYpartial"]][[length(e[["CompRateYpartial"]]) + 
        1]] <- list(p = p, pi_inv = pi_inv, ref_order = ref_order, 
        z = z, n_rank = n_rank)
    .Call("_PLMIX_CompRateYpartial", p, pi_inv, ref_order, z, 
        n_rank)
}
