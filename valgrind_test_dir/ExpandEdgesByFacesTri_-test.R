function (origV, origSubF, center, breaks) 
{
    e <- get("data.env", .GlobalEnv)
    e[["ExpandEdgesByFacesTri_"]][[length(e[["ExpandEdgesByFacesTri_"]]) + 
        1]] <- list(origV = origV, origSubF = origSubF, center = center, 
        breaks = breaks)
    .Call("_icosa_ExpandEdgesByFacesTri_", origV, origSubF, center, 
        breaks)
}
