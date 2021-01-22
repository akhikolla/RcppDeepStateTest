function (x, y) 
{
    e <- get("data.env", .GlobalEnv)
    e[["fast_match"]][[length(e[["fast_match"]]) + 1]] <- list(x = x, 
        y = y)
    .Call("_steps_fast_match", PACKAGE = "steps", x, y)
}
