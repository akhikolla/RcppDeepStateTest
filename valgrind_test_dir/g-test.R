function (T, p) 
{
    e <- get("data.env", .GlobalEnv)
    e[["g"]][[length(e[["g"]]) + 1]] <- list(T = T, p = p)
    .Call("_Opt5PL_g", T, p)
}
