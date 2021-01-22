function (Xmat, Ymat) 
{
    e <- get("data.env", .GlobalEnv)
    e[["tensorProd"]][[length(e[["tensorProd"]]) + 1]] <- list(Xmat = Xmat, 
        Ymat = Ymat)
    .Call("_GeDS_tensorProd", PACKAGE = "GeDS", Xmat, Ymat)
}
