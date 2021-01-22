function (x, prob) 
{
    e <- get("data.env", .GlobalEnv)
    e[["ldmultinom"]][[length(e[["ldmultinom"]]) + 1]] <- list(x = x, 
        prob = prob)
    .Call("_SpatialEpi_ldmultinom", PACKAGE = "SpatialEpi", x, 
        prob)
}
