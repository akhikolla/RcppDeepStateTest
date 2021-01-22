function (x, y) 
{
    e <- get("data.env", .GlobalEnv)
    e[["Matrix_Sum_C_NA"]][[length(e[["Matrix_Sum_C_NA"]]) + 
        1]] <- list(x = x, y = y)
    .Call("_BoostMLR_Matrix_Sum_C_NA", x, y)
}
