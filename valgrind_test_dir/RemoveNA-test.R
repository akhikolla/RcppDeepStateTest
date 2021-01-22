function (x) 
{
    e <- get("data.env", .GlobalEnv)
    e[["RemoveNA"]][[length(e[["RemoveNA"]]) + 1]] <- list(x = x)
    .Call("_BoostMLR_RemoveNA", x)
}
