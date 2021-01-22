function (z, scale) 
{
    e <- get("data.env", .GlobalEnv)
    e[["func_coef"]][[length(e[["func_coef"]]) + 1]] <- list(z = z, 
        scale = scale)
    .Call("_unsystation_func_coef", z, scale)
}
