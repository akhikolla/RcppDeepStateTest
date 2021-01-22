function (counts, int_cuts = as.integer(c(100, 760, 2020, 5999))) 
{
    e <- get("data.env", .GlobalEnv)
    e[["intensities"]][[length(e[["intensities"]]) + 1]] <- list(counts = counts, 
        int_cuts = int_cuts)
    .Call("_accelerometry_intensities", counts, int_cuts)
}
