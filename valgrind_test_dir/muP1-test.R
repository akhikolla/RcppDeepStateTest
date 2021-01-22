function (m, id, cm1, d) 
{
    e <- get("data.env", .GlobalEnv)
    e[["muP1"]][[length(e[["muP1"]]) + 1]] <- list(m = m, id = id, 
        cm1 = cm1, d = d)
    .Call("_trackdem_muP1", PACKAGE = "trackdem", m, id, cm1, 
        d)
}
