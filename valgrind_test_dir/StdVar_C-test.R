function (MyMat) 
{
    e <- get("data.env", .GlobalEnv)
    e[["StdVar_C"]][[length(e[["StdVar_C"]]) + 1]] <- list(MyMat = MyMat)
    .Call("_BoostMLR_StdVar_C", MyMat)
}
