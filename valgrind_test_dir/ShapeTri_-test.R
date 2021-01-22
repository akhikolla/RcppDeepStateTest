function (p0, p1, p2) 
{
    e <- get("data.env", .GlobalEnv)
    e[["ShapeTri_"]][[length(e[["ShapeTri_"]]) + 1]] <- list(p0 = p0, 
        p1 = p1, p2 = p2)
    .Call("_icosa_ShapeTri_", p0, p1, p2)
}
