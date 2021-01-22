function (codes) 
{
    e <- get("data.env", .GlobalEnv)
    e[["validate_full"]][[length(e[["validate_full"]]) + 1]] <- list(codes = codes)
    .Call("_olctools_validate_full", PACKAGE = "olctools", codes)
}
