function (lats, longs, length) 
{
    e <- get("data.env", .GlobalEnv)
    e[["encode_olc"]][[length(e[["encode_olc"]]) + 1]] <- list(lats = lats, 
        longs = longs, length = length)
    .Call("_olctools_encode_olc", PACKAGE = "olctools", lats, 
        longs, length)
}
