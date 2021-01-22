function (codes) 
{
    e <- get("data.env", .GlobalEnv)
    e[["validate_short"]][[length(e[["validate_short"]]) + 1]] <- list(codes = codes)
    .Call("_olctools_validate_short", PACKAGE = "olctools", codes)
}
