function (pi_inv, Y, z, u_bin, n_rank, rate0) 
{
    e <- get("data.env", .GlobalEnv)
    e[["CompRateP"]][[length(e[["CompRateP"]]) + 1]] <- list(pi_inv = pi_inv, 
        Y = Y, z = z, u_bin = u_bin, n_rank = n_rank, rate0 = rate0)
    .Call("_PLMIX_CompRateP", pi_inv, Y, z, u_bin, n_rank, rate0)
}
