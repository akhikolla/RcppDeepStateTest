function (pnts, gate, algorithm = 1L, epsilon = 1e-12) 
{
    e <- get("data.env", .GlobalEnv)
    e[["cpp_pnt_in_gate"]][[length(e[["cpp_pnt_in_gate"]]) + 
        1]] <- list(pnts = pnts, gate = gate, algorithm = algorithm, 
        epsilon = epsilon)
    .Call("_IFC_cpp_pnt_in_gate", pnts, gate, algorithm, epsilon)
}
