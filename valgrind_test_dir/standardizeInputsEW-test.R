function (x, n_obs, lambda, current_mean, current_var) 
{
    e <- get("data.env", .GlobalEnv)
    e[["standardizeInputsEW"]][[length(e[["standardizeInputsEW"]]) + 
        1]] <- list(x = x, n_obs = n_obs, lambda = lambda, current_mean = current_mean, 
        current_var = current_var)
    .Call("_hermiter_standardizeInputsEW", x, n_obs, lambda, 
        current_mean, current_var)
}
