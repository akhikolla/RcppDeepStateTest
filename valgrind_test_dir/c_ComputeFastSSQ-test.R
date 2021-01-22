function (subMM) 
{
    e <- get("data.env", .GlobalEnv)
    e[["c_ComputeFastSSQ"]][[length(e[["c_ComputeFastSSQ"]]) + 
        1]] <- list(subMM = subMM)
    .Call("_HistDAWass_c_ComputeFastSSQ", PACKAGE = "HistDAWass", 
        subMM)
}
