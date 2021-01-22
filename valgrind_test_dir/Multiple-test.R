function (M1, M2) 
{
    e <- get("data.env", .GlobalEnv)
    e[["Multiple"]][[length(e[["Multiple"]]) + 1]] <- list(M1 = M1, 
        M2 = M2)
    .Call("_Opt5PL_Multiple", M1, M2)
}
