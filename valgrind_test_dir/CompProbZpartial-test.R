function (p, pi_inv, Y, u_bin, n_rank, omega) 
{
    e <- get("data.env", .GlobalEnv)
    e[["CompProbZpartial"]][[length(e[["CompProbZpartial"]]) + 
        1]] <- list(p = p, pi_inv = pi_inv, Y = Y, u_bin = u_bin, 
        n_rank = n_rank, omega = omega)
    .Call("_PLMIX_CompProbZpartial", p, pi_inv, Y, u_bin, n_rank, 
        omega)
}
