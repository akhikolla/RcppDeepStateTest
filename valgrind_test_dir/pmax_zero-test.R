function (X) 
{
    e <- get("data.env", .GlobalEnv)
    e[["pmax_zero"]][[length(e[["pmax_zero"]]) + 1]] <- list(X = X)
    .Call("_steps_pmax_zero", PACKAGE = "steps", X)
}
