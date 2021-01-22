function (x_subset, x_set) 
{
    e <- get("data.env", .GlobalEnv)
    e[["Match_C_NA"]][[length(e[["Match_C_NA"]]) + 1]] <- list(x_subset = x_subset, 
        x_set = x_set)
    .Call("_BoostMLR_Match_C_NA", x_subset, x_set)
}
