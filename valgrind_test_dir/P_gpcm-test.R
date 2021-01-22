function (delta, alpha, theta, resp) 
{
    e <- get("data.env", .GlobalEnv)
    e[["P_gpcm"]][[length(e[["P_gpcm"]]) + 1]] <- list(delta = delta, 
        alpha = alpha, theta = theta, resp = resp)
    .Call("_PP_P_gpcm", delta, alpha, theta, resp)
}
