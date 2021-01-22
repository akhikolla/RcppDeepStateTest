function (MyMat) 
{
    e <- get("data.env", .GlobalEnv)
    e[["StdVar_C_NA"]][[length(e[["StdVar_C_NA"]]) + 1]] <- list(MyMat = MyMat)
    .Call("_BoostMLR_StdVar_C_NA", MyMat)
}
