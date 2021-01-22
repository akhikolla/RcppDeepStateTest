function (noise_scale, optimization_linear, optimization_state, 
    offset) 
{
    e <- get("data.env", .GlobalEnv)
    e[["log_density_laplace_conditional_"]][[length(e[["log_density_laplace_conditional_"]]) + 
        1]] <- list(noise_scale = noise_scale, optimization_linear = optimization_linear, 
        optimization_state = optimization_state, offset = offset)
    .Call("_selectiveInference_log_density_laplace_conditional_", 
        PACKAGE = "selectiveInference", noise_scale, optimization_linear, 
        optimization_state, offset)
}
