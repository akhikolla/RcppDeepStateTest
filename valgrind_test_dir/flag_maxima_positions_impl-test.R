function (values) 
{
    e <- get("data.env", .GlobalEnv)
    e[["flag_maxima_positions_impl"]][[length(e[["flag_maxima_positions_impl"]]) + 
        1]] <- list(values = values)
    .Call("_segmag_flag_maxima_positions_impl", PACKAGE = "segmag", 
        values)
}
