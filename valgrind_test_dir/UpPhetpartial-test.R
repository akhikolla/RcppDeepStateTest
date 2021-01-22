function (p, ref_order, pi_inv, u_bin, z_hat, shape0, rate0, 
    n_rank) 
{
    e <- get("data.env", .GlobalEnv)
    e[["UpPhetpartial"]][[length(e[["UpPhetpartial"]]) + 1]] <- list(p = p, 
        ref_order = ref_order, pi_inv = pi_inv, u_bin = u_bin, 
        z_hat = z_hat, shape0 = shape0, rate0 = rate0, n_rank = n_rank)
    .Call("_PLMIX_UpPhetpartial", p, ref_order, pi_inv, u_bin, 
        z_hat, shape0, rate0, n_rank)
}
