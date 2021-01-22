function (T, minLength, probVec, topCand, bottomCand) 
{
    e <- get("data.env", .GlobalEnv)
    e[["funcSEMat"]][[length(e[["funcSEMat"]]) + 1]] <- list(T = T, 
        minLength = minLength, probVec = probVec, topCand = topCand, 
        bottomCand = bottomCand)
    .Call("_unsystation_funcSEMat", T, minLength, probVec, topCand, 
        bottomCand)
}
