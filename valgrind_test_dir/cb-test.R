function (m1, m2, m3, d, e) 
{
    e <- get("data.env", .GlobalEnv)
    e[["cb"]][[length(e[["cb"]]) + 1]] <- list(m1 = m1, m2 = m2, 
        m3 = m3, d = d, e = e)
    .Call("_trackdem_cb", PACKAGE = "trackdem", m1, m2, m3, d, 
        e)
}
