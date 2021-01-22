function (z) 
{
    e <- get("data.env", .GlobalEnv)
    e[["func_dc"]][[length(e[["func_dc"]]) + 1]] <- list(z = z)
    .Call("_factorcpt_func_dc", PACKAGE = "factorcpt", z)
}
