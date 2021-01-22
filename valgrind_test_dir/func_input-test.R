function (coef, sgn) 
{
    e <- get("data.env", .GlobalEnv)
    e[["func_input"]][[length(e[["func_input"]]) + 1]] <- list(coef = coef, 
        sgn = sgn)
    .Call("_factorcpt_func_input", PACKAGE = "factorcpt", coef, 
        sgn)
}
