function (x, y) 
{
    e <- get("data.env", .GlobalEnv)
    e[["NumericVectorEquality"]][[length(e[["NumericVectorEquality"]]) + 
        1]] <- list(x = x, y = y)
    .Call("_SpatialEpi_NumericVectorEquality", PACKAGE = "SpatialEpi", 
        x, y)
}
