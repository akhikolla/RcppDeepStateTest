function (m1, bg, d, e) 
{
    e <- get("data.env", .GlobalEnv)
    e[["sb"]][[length(e[["sb"]]) + 1]] <- list(m1 = m1, bg = bg, 
        d = d, e = e)
    .Call("_trackdem_sb", PACKAGE = "trackdem", m1, bg, d, e)
}
