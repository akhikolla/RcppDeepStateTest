function (x, y, m_x = 0L, m_y = 0L) 
{
    e <- get("data.env", .GlobalEnv)
    e[["Jeffreys_mi"]][[length(e[["Jeffreys_mi"]]) + 1]] <- list(x = x, 
        y = y, m_x = m_x, m_y = m_y)
    .Call("_BNSL_Jeffreys_mi", x, y, m_x, m_y)
}
