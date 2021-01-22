function () 
{
    e <- get("data.env", .GlobalEnv)
    e[["interpolateLinearGrid"]][[length(e[["interpolateLinearGrid"]]) + 
        1]] <- list()
    list(NULL, character(0))
}
