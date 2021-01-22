function (min, max) 
{
    e <- get("data.env", .GlobalEnv)
    e[["shuffle_vec"]][[length(e[["shuffle_vec"]]) + 1]] <- list(min = min, 
        max = max)
    .Call("_steps_shuffle_vec", PACKAGE = "steps", min, max)
}
