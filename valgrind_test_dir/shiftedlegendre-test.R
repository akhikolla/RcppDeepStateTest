function (rmax) 
{
    e <- get("data.env", .GlobalEnv)
    e[["shiftedlegendre"]][[length(e[["shiftedlegendre"]]) + 
        1]] <- list(rmax = rmax)
    .Call("_Lmoments_shiftedlegendre", PACKAGE = "Lmoments", 
        rmax)
}
