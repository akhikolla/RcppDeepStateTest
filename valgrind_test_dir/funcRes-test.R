function (yMat, M, minLength, probVec, topCand, bottomCand, var) 
{
    e <- get("data.env", .GlobalEnv)
    e[["funcRes"]][[length(e[["funcRes"]]) + 1]] <- list(yMat = yMat, 
        M = M, minLength = minLength, probVec = probVec, topCand = topCand, 
        bottomCand = bottomCand, var = var)
    .Call("_unsystation_funcRes", yMat, M, minLength, probVec, 
        topCand, bottomCand, var)
}
