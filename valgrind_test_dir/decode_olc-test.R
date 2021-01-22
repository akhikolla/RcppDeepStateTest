function (olcs) 
{
    e <- get("data.env", .GlobalEnv)
    e[["decode_olc"]][[length(e[["decode_olc"]]) + 1]] <- list(olcs = olcs)
    .Call("_olctools_decode_olc", PACKAGE = "olctools", olcs)
}
