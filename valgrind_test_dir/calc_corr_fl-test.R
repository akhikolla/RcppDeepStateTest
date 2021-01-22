function (samp_mat) 
{
    e <- get("data.env", .GlobalEnv)
    e[["calc_corr_fl"]][[length(e[["calc_corr_fl"]]) + 1]] <- list(samp_mat = samp_mat)
    .Call("_BAMBI_calc_corr_fl", samp_mat)
}
