function (x, hyper = 1000, base = 10, lin_comp = 2.302585) 
{
    e <- get("data.env", .GlobalEnv)
    e[["cpp_inv_smoothLinLog"]][[length(e[["cpp_inv_smoothLinLog"]]) + 
        1]] <- list(x = x, hyper = hyper, base = base, lin_comp = lin_comp)
    .Call("_IFC_cpp_inv_smoothLinLog", x, hyper, base, lin_comp)
}
