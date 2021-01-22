function (x, y, m_x = 0L, m_y = 0L, d = 1) 
{
    e <- get("data.env", .GlobalEnv)
    e[["BDeu_mi"]][[length(e[["BDeu_mi"]]) + 1]] <- list(x = x, 
        y = y, m_x = m_x, m_y = m_y, d = d)
    .Call("_BNSL_BDeu_mi", x, y, m_x, m_y, d)
}
