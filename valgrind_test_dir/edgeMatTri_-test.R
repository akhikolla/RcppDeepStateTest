function (v, e) 
{
    e <- get("data.env", .GlobalEnv)
    e[["edgeMatTri_"]][[length(e[["edgeMatTri_"]]) + 1]] <- list(v = v, 
        e = e)
    .Call("_icosa_edgeMatTri_", v, e)
}
