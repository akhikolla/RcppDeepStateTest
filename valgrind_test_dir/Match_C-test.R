function (x_subset, x_set) 
{
    e <- get("data.env", .GlobalEnv)
    e[["Match_C"]][[length(e[["Match_C"]]) + 1]] <- list(x_subset = x_subset, 
        x_set = x_set)
    .Call("_BoostMLR_Match_C", x_subset, x_set)
}
