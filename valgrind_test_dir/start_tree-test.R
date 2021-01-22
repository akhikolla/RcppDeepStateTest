function (start_mean, start_sd) 
{
    e <- get("data.env", .GlobalEnv)
    e[["start_tree"]][[length(e[["start_tree"]]) + 1]] <- list(start_mean = start_mean, 
        start_sd = start_sd)
    .Call("_bartBMA_start_tree", start_mean, start_sd)
}
