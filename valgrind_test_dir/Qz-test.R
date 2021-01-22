function (zeta1, zeta2) 
{
    e <- get("data.env", .GlobalEnv)
    e[["Qz"]][[length(e[["Qz"]]) + 1]] <- list(zeta1 = zeta1, 
        zeta2 = zeta2)
    .Call("_RJafroc_Qz", PACKAGE = "RJafroc", zeta1, zeta2)
}
