function (v, f) 
{
    e <- get("data.env", .GlobalEnv)
    e[["AllShapeTri_"]][[length(e[["AllShapeTri_"]]) + 1]] <- list(v = v, 
        f = f)
    .Call("_icosa_AllShapeTri_", v, f)
}
