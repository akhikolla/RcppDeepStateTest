function (Xm, Cm, OUm, OCm, I, T) 
{
    e <- get("data.env", .GlobalEnv)
    e[["p_covUsparse"]][[length(e[["p_covUsparse"]]) + 1]] <- list(Xm = Xm, 
        Cm = Cm, OUm = OUm, OCm = OCm, I = I, T = T)
    invisible(c(".Call", "'_CMF_p_covUsparse`", "Xm", "Cm", "OUm", 
    "OCm", "I", "T"))
}
