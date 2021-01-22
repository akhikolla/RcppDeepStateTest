function (V) 
{
    e <- get("data.env", .GlobalEnv)
    e[["cpp_computeGamma"]][[length(e[["cpp_computeGamma"]]) + 
        1]] <- list(V = V)
    .Call("_IFC_cpp_computeGamma", V)
}
