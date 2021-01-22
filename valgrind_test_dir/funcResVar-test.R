function (yMat, seMat, tmpVar) 
{
    e <- get("data.env", .GlobalEnv)
    e[["funcResVar"]][[length(e[["funcResVar"]]) + 1]] <- list(yMat = yMat, 
        seMat = seMat, tmpVar = tmpVar)
    .Call("_unsystation_funcResVar", yMat, seMat, tmpVar)
}
