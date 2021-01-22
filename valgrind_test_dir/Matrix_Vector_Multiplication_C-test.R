function (x, y) 
{
    e <- get("data.env", .GlobalEnv)
    e[["Matrix_Vector_Multiplication_C"]][[length(e[["Matrix_Vector_Multiplication_C"]]) + 
        1]] <- list(x = x, y = y)
    .Call("_BoostMLR_Matrix_Vector_Multiplication_C", x, y)
}
