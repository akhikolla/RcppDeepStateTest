function (y, gen, R2 = 0.5, alpha = 0.02) 
{
    e <- get("data.env", .GlobalEnv)
    e[["emBL"]][[length(e[["emBL"]]) + 1]] <- list(y = y, gen = gen, 
        R2 = R2, alpha = alpha)
    .Call("_NAM_emBL", y, gen, R2, alpha)
}
