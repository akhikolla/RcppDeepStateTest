function (segmentation_magnitude_overall, index_keypresses, gauss_values, 
    gauss_n_indexes_per_side, indexes_gauss_offset) 
{
    e <- get("data.env", .GlobalEnv)
    e[["calc_segmentation_magnitude_impl"]][[length(e[["calc_segmentation_magnitude_impl"]]) + 
        1]] <- list(segmentation_magnitude_overall = segmentation_magnitude_overall, 
        index_keypresses = index_keypresses, gauss_values = gauss_values, 
        gauss_n_indexes_per_side = gauss_n_indexes_per_side, 
        indexes_gauss_offset = indexes_gauss_offset)
    invisible(c(".Call", "_segmag_calc_segmentation_magnitude_impl", 
    "segmag", "segmentation_magnitude_overall", "index_keypresses", 
    "gauss_values", "gauss_n_indexes_per_side", "indexes_gauss_offset"
    ))
}
