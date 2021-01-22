function (v, f) 
{
    e <- get("data.env", .GlobalEnv)
    e[["triMatTri_"]][[length(e[["triMatTri_"]]) + 1]] <- list(v = v, 
        f = f)
    .Call("_icosa_triMatTri_", v, f)
}
