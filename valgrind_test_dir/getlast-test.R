function (trajectories) 
{
    e <- get("data.env", .GlobalEnv)
    e[["getlast"]][[length(e[["getlast"]]) + 1]] <- list(trajectories = trajectories)
    .Call("_mousetrap_getlast", trajectories)
}
