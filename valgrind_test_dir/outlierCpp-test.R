function (K, R, xy, ratio, imat, rmin) 
{
    e <- get("data.env", .GlobalEnv)
    e[["outlierCpp"]][[length(e[["outlierCpp"]]) + 1]] <- list(K = K, 
        R = R, xy = xy, ratio = ratio, imat = imat, rmin = rmin)
    invisible(c(".Call", "'_Benchmarking_outlierCpp`", "K", "R", 
    "xy", "ratio", "imat", "rmin"))
}
