function (m, id, cm1, d) 
{
    e <- get("data.env", .GlobalEnv)
    e[["sdP1"]][[length(e[["sdP1"]]) + 1]] <- list(m = m, id = id, 
        cm1 = cm1, d = d)
    .Call("_trackdem_sdP1", PACKAGE = "trackdem", m, id, cm1, 
        d)
}
