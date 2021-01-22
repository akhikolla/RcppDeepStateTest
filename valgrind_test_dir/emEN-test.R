function (y, gen, R2 = 0.5, alpha = 0.02) 
{
    e <- get("data.env", .GlobalEnv)
    e[["emEN"]][[length(e[["emEN"]]) + 1]] <- list(y = y, gen = gen, 
        R2 = R2, alpha = alpha)
    .Call("_NAM_emEN", y, gen, R2, alpha)
}
