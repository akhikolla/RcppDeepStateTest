function (x, hyper = 1000, base = 10, lin_comp = 2.302585) 
{
    e <- get("data.env", .GlobalEnv)
    e[["cpp_smoothLinLog"]][[length(e[["cpp_smoothLinLog"]]) + 
        1]] <- list(x = x, hyper = hyper, base = base, lin_comp = lin_comp)
    .Call("_IFC_cpp_smoothLinLog", x, hyper, base, lin_comp)
}
