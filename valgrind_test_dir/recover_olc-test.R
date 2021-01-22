function (olcs, lats, longs) 
{
    e <- get("data.env", .GlobalEnv)
    e[["recover_olc"]][[length(e[["recover_olc"]]) + 1]] <- list(olcs = olcs, 
        lats = lats, longs = longs)
    .Call("_olctools_recover_olc", PACKAGE = "olctools", olcs, 
        lats, longs)
}
