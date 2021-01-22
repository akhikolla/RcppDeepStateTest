function (m, id, cm1, cm2, cm3, d) 
{
    e <- get("data.env", .GlobalEnv)
    e[["sdP"]][[length(e[["sdP"]]) + 1]] <- list(m = m, id = id, 
        cm1 = cm1, cm2 = cm2, cm3 = cm3, d = d)
    .Call("_trackdem_sdP", PACKAGE = "trackdem", m, id, cm1, 
        cm2, cm3, d)
}
