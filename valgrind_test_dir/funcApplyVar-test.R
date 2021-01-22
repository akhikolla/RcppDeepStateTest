function (nullStatMat, maxLevel, Msq) 
{
    e <- get("data.env", .GlobalEnv)
    e[["funcApplyVar"]][[length(e[["funcApplyVar"]]) + 1]] <- list(nullStatMat = nullStatMat, 
        maxLevel = maxLevel, Msq = Msq)
    .Call("_unsystation_funcApplyVar", nullStatMat, maxLevel, 
        Msq)
}
