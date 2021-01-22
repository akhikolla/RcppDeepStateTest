function (x, y, z, m_x = 0L, m_y = 0L, m_z = 0L) 
{
    e <- get("data.env", .GlobalEnv)
    e[["Jeffreys_cmi"]][[length(e[["Jeffreys_cmi"]]) + 1]] <- list(x = x, 
        y = y, z = z, m_x = m_x, m_y = m_y, m_z = m_z)
    .Call("_BNSL_Jeffreys_cmi", x, y, z, m_x, m_y, m_z)
}
