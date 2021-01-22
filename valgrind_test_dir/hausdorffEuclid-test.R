function (x, y) 
{
    e <- get("data.env", .GlobalEnv)
    e[["hausdorffEuclid"]][[length(e[["hausdorffEuclid"]]) + 
        1]] <- list(x = x, y = y)
    .Call("_hutilscpp_hausdorffEuclid", x, y)
}
