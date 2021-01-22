function (input_data, depth) 
{
    e <- get("data.env", .GlobalEnv)
    e[["compute_counts"]][[length(e[["compute_counts"]]) + 1]] <- list(input_data = input_data, 
        depth = depth)
    .Call("_BCT_compute_counts", input_data, depth)
}
