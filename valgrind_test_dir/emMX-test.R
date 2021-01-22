function (y, gen, R2 = 0.5) 
{
    e <- get("data.env", .GlobalEnv)
    e[["emMX"]][[length(e[["emMX"]]) + 1]] <- list(y = y, gen = gen, 
        R2 = R2)
    .Call("_NAM_emMX", y, gen, R2)
}
