function (values, loc) 
{
    e <- get("data.env", .GlobalEnv)
    e[["OccupiedCellUpSampling_"]][[length(e[["OccupiedCellUpSampling_"]]) + 
        1]] <- list(values = values, loc = loc)
    .Call("_icosa_OccupiedCellUpSampling_", values, loc)
}
