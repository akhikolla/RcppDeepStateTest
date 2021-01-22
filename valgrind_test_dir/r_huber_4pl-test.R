function (delta, alpha, theta, la, ua, H) 
{
    e <- get("data.env", .GlobalEnv)
    e[["r_huber_4pl"]][[length(e[["r_huber_4pl"]]) + 1]] <- list(delta = delta, 
        alpha = alpha, theta = theta, la = la, ua = ua, H = H)
    .Call("_PP_r_huber_4pl", delta, alpha, theta, la, ua, H)
}
