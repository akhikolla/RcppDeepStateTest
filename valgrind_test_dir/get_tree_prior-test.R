function (spike_tree, s_t_hyperprior, p_s_t, a_s_t, b_s_t, num_obs, 
    num_vars, lambda_poisson, tree_table, tree_matrix, alpha, 
    beta) 
{
    e <- get("data.env", .GlobalEnv)
    e[["get_tree_prior"]][[length(e[["get_tree_prior"]]) + 1]] <- list(spike_tree = spike_tree, 
        s_t_hyperprior = s_t_hyperprior, p_s_t = p_s_t, a_s_t = a_s_t, 
        b_s_t = b_s_t, num_obs = num_obs, num_vars = num_vars, 
        lambda_poisson = lambda_poisson, tree_table = tree_table, 
        tree_matrix = tree_matrix, alpha = alpha, beta = beta)
    .Call("_bartBMA_get_tree_prior", spike_tree, s_t_hyperprior, 
        p_s_t, a_s_t, b_s_t, num_obs, num_vars, lambda_poisson, 
        tree_table, tree_matrix, alpha, beta)
}
