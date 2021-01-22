function (y, gen, df = 10, R2 = 0.5) 
{
    e <- get("data.env", .GlobalEnv)
    e[["emRR"]][[length(e[["emRR"]]) + 1]] <- list(y = y, gen = gen, 
        df = df, R2 = R2)
    .Call("_NAM_emRR", y, gen, df, R2)
}
