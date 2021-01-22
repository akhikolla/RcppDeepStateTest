function (codes) 
{
    e <- get("data.env", .GlobalEnv)
    e[["validate_olc"]][[length(e[["validate_olc"]]) + 1]] <- list(codes = codes)
    .Call("_olctools_validate_olc", PACKAGE = "olctools", codes)
}
