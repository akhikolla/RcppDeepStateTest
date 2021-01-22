function (x) 
{
    e <- get("data.env", .GlobalEnv)
    e[["Diag_Matrix_C"]][[length(e[["Diag_Matrix_C"]]) + 1]] <- list(x = x)
    .Call("_BoostMLR_Diag_Matrix_C", x)
}
