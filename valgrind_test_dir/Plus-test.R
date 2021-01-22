function (M1, M2) 
{
    e <- get("data.env", .GlobalEnv)
    e[["Plus"]][[length(e[["Plus"]]) + 1]] <- list(M1 = M1, M2 = M2)
    .Call("_Opt5PL_Plus", M1, M2)
}
