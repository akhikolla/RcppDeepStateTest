function (SW, SWCON, SORW, KROCW, NOW) 
{
    e <- get("data.env", .GlobalEnv)
    e[["krow2p_BC"]][[length(e[["krow2p_BC"]]) + 1]] <- list(SW = SW, 
        SWCON = SWCON, SORW = SORW, KROCW = KROCW, NOW = NOW)
    .Call("_Rrelperm_krow2p_BC", SW, SWCON, SORW, KROCW, NOW)
}
