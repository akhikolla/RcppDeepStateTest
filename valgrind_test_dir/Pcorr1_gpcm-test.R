function (delta, alpha, theta) 
{
    e <- get("data.env", .GlobalEnv)
    e[["Pcorr1_gpcm"]][[length(e[["Pcorr1_gpcm"]]) + 1]] <- list(delta = delta, 
        alpha = alpha, theta = theta)
    .Call("_PP_Pcorr1_gpcm", delta, alpha, theta)
}
