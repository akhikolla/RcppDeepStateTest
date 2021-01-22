function (SWCON, SOIRG, SORG, SGCON, SGCRIT, KRGCL, KROGCG, NG, 
    NOG, NP) 
{
    e <- get("data.env", .GlobalEnv)
    e[["kr2p_gl_cpp"]][[length(e[["kr2p_gl_cpp"]]) + 1]] <- list(SWCON = SWCON, 
        SOIRG = SOIRG, SORG = SORG, SGCON = SGCON, SGCRIT = SGCRIT, 
        KRGCL = KRGCL, KROGCG = KROGCG, NG = NG, NOG = NOG, NP = NP)
    .Call("_Rrelperm_kr2p_gl_cpp", SWCON, SOIRG, SORG, SGCON, 
        SGCRIT, KRGCL, KROGCG, NG, NOG, NP)
}
