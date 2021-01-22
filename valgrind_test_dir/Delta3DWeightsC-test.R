function (vx, Datasample) 
{
    e <- get("data.env", .GlobalEnv)
    e[["Delta3DWeightsC"]][[length(e[["Delta3DWeightsC"]]) + 
        1]] <- list(vx = vx, Datasample = Datasample)
    .Call("_GeneralizedUmatrix_Delta3DWeightsC", vx, Datasample)
}
