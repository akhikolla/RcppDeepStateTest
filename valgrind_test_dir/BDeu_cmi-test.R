function (x, y, z, m_x = 0L, m_y = 0L, m_z = 0L, d = 1) 
{
    e <- get("data.env", .GlobalEnv)
    e[["BDeu_cmi"]][[length(e[["BDeu_cmi"]]) + 1]] <- list(x = x, 
        y = y, z = z, m_x = m_x, m_y = m_y, m_z = m_z, d = d)
    .Call("_BNSL_BDeu_cmi", x, y, z, m_x, m_y, m_z, d)
}
