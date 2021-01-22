function (olcs, lats, longs) 
{
    e <- get("data.env", .GlobalEnv)
    e[["shorten_olc"]][[length(e[["shorten_olc"]]) + 1]] <- list(olcs = olcs, 
        lats = lats, longs = longs)
    .Call("_olctools_shorten_olc", PACKAGE = "olctools", olcs, 
        lats, longs)
}
