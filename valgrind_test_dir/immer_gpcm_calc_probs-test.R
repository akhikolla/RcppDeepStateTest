function (theta, b, a) 
{
    e <- get("data.env", .GlobalEnv)
    e[["immer_gpcm_calc_probs"]][[length(e[["immer_gpcm_calc_probs"]]) + 
        1]] <- list(theta = theta, b = b, a = a)
    .Call("_immer_immer_gpcm_calc_probs", PACKAGE = "immer", 
        theta, b, a)
}
