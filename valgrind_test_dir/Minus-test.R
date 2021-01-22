function (M1, M2) 
{
    e <- get("data.env", .GlobalEnv)
    e[["Minus"]][[length(e[["Minus"]]) + 1]] <- list(M1 = M1, 
        M2 = M2)
    .Call("_Opt5PL_Minus", M1, M2)
}
