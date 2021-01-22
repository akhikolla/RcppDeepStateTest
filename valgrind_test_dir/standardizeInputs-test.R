function (x, n_obs, current_mean, current_var) 
{
    e <- get("data.env", .GlobalEnv)
    e[["standardizeInputs"]][[length(e[["standardizeInputs"]]) + 
        1]] <- list(x = x, n_obs = n_obs, current_mean = current_mean, 
        current_var = current_var)
    .Call("_hermiter_standardizeInputs", x, n_obs, current_mean, 
        current_var)
}
