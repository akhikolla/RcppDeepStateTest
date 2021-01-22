function (SWCON, SWCRIT, SOIRW, SORW, KRWIRO, KROCW, NW, NOW, 
    NP) 
{
    e <- get("data.env", .GlobalEnv)
    e[["kr2p_ow_cpp"]][[length(e[["kr2p_ow_cpp"]]) + 1]] <- list(SWCON = SWCON, 
        SWCRIT = SWCRIT, SOIRW = SOIRW, SORW = SORW, KRWIRO = KRWIRO, 
        KROCW = KROCW, NW = NW, NOW = NOW, NP = NP)
    .Call("_Rrelperm_kr2p_ow_cpp", SWCON, SWCRIT, SOIRW, SORW, 
        KRWIRO, KROCW, NW, NOW, NP)
}
