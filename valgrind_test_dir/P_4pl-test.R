function (delta, alpha, theta, la, ua) 
{
    e <- get("data.env", .GlobalEnv)
    e[["P_4pl"]][[length(e[["P_4pl"]]) + 1]] <- list(delta = delta, 
        alpha = alpha, theta = theta, la = la, ua = ua)
    .Call("_PP_P_4pl", delta, alpha, theta, la, ua)
}
