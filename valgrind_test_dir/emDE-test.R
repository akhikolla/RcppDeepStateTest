function (y, gen, R2 = 0.5) 
{
    e <- get("data.env", .GlobalEnv)
    e[["emDE"]][[length(e[["emDE"]]) + 1]] <- list(y = y, gen = gen, 
        R2 = R2)
    .Call("_NAM_emDE", y, gen, R2)
}
