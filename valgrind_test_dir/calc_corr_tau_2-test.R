function (samp_mat) 
{
    e <- get("data.env", .GlobalEnv)
    e[["calc_corr_tau_2"]][[length(e[["calc_corr_tau_2"]]) + 
        1]] <- list(samp_mat = samp_mat)
    .Call("_BAMBI_calc_corr_tau_2", samp_mat)
}
