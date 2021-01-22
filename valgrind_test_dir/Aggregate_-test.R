function (gridPoints, queries, origin) 
{
    e <- get("data.env", .GlobalEnv)
    e[["Aggregate_"]][[length(e[["Aggregate_"]]) + 1]] <- list(gridPoints = gridPoints, 
        queries = queries, origin = origin)
    .Call("_icosa_Aggregate_", gridPoints, queries, origin)
}
