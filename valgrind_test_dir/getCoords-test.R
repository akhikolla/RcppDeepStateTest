function (m, d) 
{
    e <- get("data.env", .GlobalEnv)
    e[["getCoords"]][[length(e[["getCoords"]]) + 1]] <- list(m = m, 
        d = d)
    .Call("_trackdem_getCoords", PACKAGE = "trackdem", m, d)
}
