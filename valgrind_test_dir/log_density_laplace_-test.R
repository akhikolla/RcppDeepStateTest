function (noise_scale, internal_linear, internal_state, optimization_linear, 
    optimization_state, offset) 
{
    e <- get("data.env", .GlobalEnv)
    e[["log_density_laplace_"]][[length(e[["log_density_laplace_"]]) + 
        1]] <- list(noise_scale = noise_scale, internal_linear = internal_linear, 
        internal_state = internal_state, optimization_linear = optimization_linear, 
        optimization_state = optimization_state, offset = offset)
    .Call("_selectiveInference_log_density_laplace_", PACKAGE = "selectiveInference", 
        noise_scale, internal_linear, internal_state, optimization_linear, 
        optimization_state, offset)
}
