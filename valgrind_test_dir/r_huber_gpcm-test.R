function (delta, alpha, theta, H) 
{
    e <- get("data.env", .GlobalEnv)
    e[["r_huber_gpcm"]][[length(e[["r_huber_gpcm"]]) + 1]] <- list(delta = delta, 
        alpha = alpha, theta = theta, H = H)
    .Call("_PP_r_huber_gpcm", delta, alpha, theta, H)
}
