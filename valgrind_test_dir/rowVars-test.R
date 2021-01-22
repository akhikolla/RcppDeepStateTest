function (mat_in) 
{
    e <- get("data.env", .GlobalEnv)
    e[["rowVars"]][[length(e[["rowVars"]]) + 1]] <- list(mat_in = mat_in)
    .Call("_BAMBI_rowVars", mat_in)
}
