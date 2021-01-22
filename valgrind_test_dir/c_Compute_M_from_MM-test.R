function (subMM) 
{
    e <- get("data.env", .GlobalEnv)
    e[["c_Compute_M_from_MM"]][[length(e[["c_Compute_M_from_MM"]]) + 
        1]] <- list(subMM = subMM)
    .Call("_HistDAWass_c_Compute_M_from_MM", PACKAGE = "HistDAWass", 
        subMM)
}
