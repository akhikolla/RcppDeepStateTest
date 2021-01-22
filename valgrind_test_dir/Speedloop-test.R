function (A, x, y) 
{
    e <- get("data.env", .GlobalEnv)
    e[["Speedloop"]][[length(e[["Speedloop"]]) + 1]] <- list(A = A, 
        x = x, y = y)
    .Call("_splithalf_Speedloop", A, x, y)
}
