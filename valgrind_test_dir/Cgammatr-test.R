function (n, A, B, range) 
{
    e <- get("data.env", .GlobalEnv)
    e[["Cgammatr"]][[length(e[["Cgammatr"]]) + 1]] <- list(n = n, 
        A = A, B = B, range = range)
    .Call("_RGeode_Cgammatr", PACKAGE = "RGeode", n, A, B, range)
}
