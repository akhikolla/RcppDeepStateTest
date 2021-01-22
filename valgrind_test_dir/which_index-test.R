function (indices, m) 
{
    e <- get("data.env", .GlobalEnv)
    e[["which_index"]][[length(e[["which_index"]]) + 1]] <- list(indices = indices, 
        m = m)
    .Call("_Quartet_which_index", indices, m)
}
