function (delta, alpha, theta, la, ua) 
{
    e <- get("data.env", .GlobalEnv)
    e[["P_4pl4wle"]][[length(e[["P_4pl4wle"]]) + 1]] <- list(delta = delta, 
        alpha = alpha, theta = theta, la = la, ua = ua)
    .Call("_PP_P_4pl4wle", delta, alpha, theta, la, ua)
}
