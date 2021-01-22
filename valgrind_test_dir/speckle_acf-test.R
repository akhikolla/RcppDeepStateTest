function (ps) 
{
    e <- get("data.env", .GlobalEnv)
    e[["speckle_acf"]][[length(e[["speckle_acf"]]) + 1]] <- list(ps = ps)
    .Call("_specklestar_speckle_acf", PACKAGE = "specklestar", 
        ps)
}
