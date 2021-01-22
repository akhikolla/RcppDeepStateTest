function (counts, int_cuts = as.integer(c(100, 760, 2020, 5999))) 
{
    e <- get("data.env", .GlobalEnv)
    e[["cut_counts"]][[length(e[["cut_counts"]]) + 1]] <- list(counts = counts, 
        int_cuts = int_cuts)
    .Call("_accelerometry_cut_counts", counts, int_cuts)
}
