function (coef, buffMat) 
{
    e <- get("data.env", .GlobalEnv)
    e[["funcSimX"]][[length(e[["funcSimX"]]) + 1]] <- list(coef = coef, 
        buffMat = buffMat)
    .Call("_unsystation_funcSimX", coef, buffMat)
}
