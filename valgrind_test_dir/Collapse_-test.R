function (vect) 
{
    e <- get("data.env", .GlobalEnv)
    e[["Collapse_"]][[length(e[["Collapse_"]]) + 1]] <- list(vect = vect)
    .Call("_icosa_Collapse_", vect)
}
