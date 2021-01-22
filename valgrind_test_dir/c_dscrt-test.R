function (y, z, l) 
{
    e <- get("data.env", .GlobalEnv)
    e[["c_dscrt"]][[length(e[["c_dscrt"]]) + 1]] <- list(y = y, 
        z = z, l = l)
    .Call("_cgAUC_c_dscrt", PACKAGE = "cgAUC", y, z, l)
}
