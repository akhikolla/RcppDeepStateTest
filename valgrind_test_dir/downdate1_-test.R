function (Q1, R, j0, m, n) 
{
    e <- get("data.env", .GlobalEnv)
    e[["downdate1_"]][[length(e[["downdate1_"]]) + 1]] <- list(Q1 = Q1, 
        R = R, j0 = j0, m = m, n = n)
    .Call("_selectiveInference_downdate1_", PACKAGE = "selectiveInference", 
        Q1, R, j0, m, n)
}
