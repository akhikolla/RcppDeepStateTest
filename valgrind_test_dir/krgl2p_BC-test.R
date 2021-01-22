function (SG, SWCON, SORG, SGCON, KROGCG, NOG) 
{
    e <- get("data.env", .GlobalEnv)
    e[["krgl2p_BC"]][[length(e[["krgl2p_BC"]]) + 1]] <- list(SG = SG, 
        SWCON = SWCON, SORG = SORG, SGCON = SGCON, KROGCG = KROGCG, 
        NOG = NOG)
    .Call("_Rrelperm_krgl2p_BC", SG, SWCON, SORG, SGCON, KROGCG, 
        NOG)
}
