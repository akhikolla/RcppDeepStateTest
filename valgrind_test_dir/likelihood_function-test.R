function (y_temp, treetable_temp, obs_to_nodes_temp, a, mu, nu, 
    lambda) 
{
    e <- get("data.env", .GlobalEnv)
    e[["likelihood_function"]][[length(e[["likelihood_function"]]) + 
        1]] <- list(y_temp = y_temp, treetable_temp = treetable_temp, 
        obs_to_nodes_temp = obs_to_nodes_temp, a = a, mu = mu, 
        nu = nu, lambda = lambda)
    .Call("_bartBMA_likelihood_function", y_temp, treetable_temp, 
        obs_to_nodes_temp, a, mu, nu, lambda)
}
