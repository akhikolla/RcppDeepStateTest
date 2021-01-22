function (A) 
{
    e <- get("data.env", .GlobalEnv)
    e[["chol_LO"]][[length(e[["chol_LO"]]) + 1]] <- list(A = A)
    .Call("_Benchmarking_chol_LO", A)
}
