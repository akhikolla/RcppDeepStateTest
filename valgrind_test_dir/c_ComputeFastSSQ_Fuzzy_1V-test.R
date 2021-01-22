function (M, memb, m) 
{
    e <- get("data.env", .GlobalEnv)
    e[["c_ComputeFastSSQ_Fuzzy_1V"]][[length(e[["c_ComputeFastSSQ_Fuzzy_1V"]]) + 
        1]] <- list(M = M, memb = memb, m = m)
    .Call("_HistDAWass_c_ComputeFastSSQ_Fuzzy_1V", PACKAGE = "HistDAWass", 
        M, memb, m)
}
