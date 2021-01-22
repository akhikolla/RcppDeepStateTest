function (design, response, theta, Ki, ct) 
{
    e <- get("data.env", .GlobalEnv)
    e[["C_GP_cpp"]][[length(e[["C_GP_cpp"]]) + 1]] <- list(design = design, 
        response = response, theta = theta, Ki = Ki, ct = ct)
    .Call("_activegp_C_GP_cpp", PACKAGE = "activegp", design, 
        response, theta, Ki, ct)
}
