function (beta, alpha, lowerA, upperA, theta) 
{
    e <- get("data.env", .GlobalEnv)
    e[["sim_4pl"]][[length(e[["sim_4pl"]]) + 1]] <- list(beta = beta, 
        alpha = alpha, lowerA = lowerA, upperA = upperA, theta = theta)
    .Call("_PP_sim_4pl", beta, alpha, lowerA, upperA, theta)
}
