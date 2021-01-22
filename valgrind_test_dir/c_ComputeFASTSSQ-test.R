function (subMM) 
{
    e <- get("data.env", .GlobalEnv)
    e[["c_ComputeFASTSSQ"]][[length(e[["c_ComputeFASTSSQ"]]) + 
        1]] <- list(subMM = subMM)
    .Call("_HistDAWass_c_ComputeFASTSSQ", PACKAGE = "HistDAWass", 
        subMM)
}
