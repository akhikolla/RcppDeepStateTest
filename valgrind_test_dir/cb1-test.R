function (m1, d, e) 
{
    e <- get("data.env", .GlobalEnv)
    e[["cb1"]][[length(e[["cb1"]]) + 1]] <- list(m1 = m1, d = d, 
        e = e)
    .Call("_trackdem_cb1", PACKAGE = "trackdem", m1, d, e)
}
