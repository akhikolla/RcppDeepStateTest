function (Xm, Gm, CUm, OUm, Cm, I, T, Rowm, Colm) 
{
    e <- get("data.env", .GlobalEnv)
    e[["p_gradUsparse"]][[length(e[["p_gradUsparse"]]) + 1]] <- list(Xm = Xm, 
        Gm = Gm, CUm = CUm, OUm = OUm, Cm = Cm, I = I, T = T, 
        Rowm = Rowm, Colm = Colm)
    invisible(c(".Call", "'_CMF_p_gradUsparse`", "Xm", "Gm", 
    "CUm", "OUm", "Cm", "I", "T", "Rowm", "Colm"))
}
