function (coef) 
{
    e <- get("data.env", .GlobalEnv)
    e[["func_input_on"]][[length(e[["func_input_on"]]) + 1]] <- list(coef = coef)
    .Call("_factorcpt_func_input_on", PACKAGE = "factorcpt", 
        coef)
}
