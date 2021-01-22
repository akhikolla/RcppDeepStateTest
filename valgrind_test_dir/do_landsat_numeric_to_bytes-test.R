function (m, bits) 
{
    e <- get("data.env", .GlobalEnv)
    e[["do_landsat_numeric_to_bytes"]][[length(e[["do_landsat_numeric_to_bytes"]]) + 
        1]] <- list(m = m, bits = bits)
    .Call("_oce_do_landsat_numeric_to_bytes", m, bits)
}
