function (SWCON, SWCRIT, SOIRW, SORW, SOIRG, SORG, SGCON, SGCRIT, 
    KRWIRO, KROCW, KRGCL, NW, NOW, NG, NOG, NP) 
{
    e <- get("data.env", .GlobalEnv)
    e[["kr3p_StoneII_So_cpp"]][[length(e[["kr3p_StoneII_So_cpp"]]) + 
        1]] <- list(SWCON = SWCON, SWCRIT = SWCRIT, SOIRW = SOIRW, 
        SORW = SORW, SOIRG = SOIRG, SORG = SORG, SGCON = SGCON, 
        SGCRIT = SGCRIT, KRWIRO = KRWIRO, KROCW = KROCW, KRGCL = KRGCL, 
        NW = NW, NOW = NOW, NG = NG, NOG = NOG, NP = NP)
    .Call("_Rrelperm_kr3p_StoneII_So_cpp", SWCON, SWCRIT, SOIRW, 
        SORW, SOIRG, SORG, SGCON, SGCRIT, KRWIRO, KROCW, KRGCL, 
        NW, NOW, NG, NOG, NP)
}
