function (T, p) 
{
    e <- get("data.env", .GlobalEnv)
    e[["Dp"]][[length(e[["Dp"]]) + 1]] <- list(T = T, p = p)
    .Call("_Opt5PL_Dp", T, p)
}
