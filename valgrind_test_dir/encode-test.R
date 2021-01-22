function (line, precision = 5L, third_dim = 3L, third_dim_precision = 5L) 
{
    e <- get("data.env", .GlobalEnv)
    e[["encode"]][[length(e[["encode"]]) + 1]] <- list(line = line, 
        precision = precision, third_dim = third_dim, third_dim_precision = third_dim_precision)
    .Call("_flexpolyline_encode", line, precision, third_dim, 
        third_dim_precision)
}
