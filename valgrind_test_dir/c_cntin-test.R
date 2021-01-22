function (y, z, l, h) 
{
    e <- get("data.env", .GlobalEnv)
    e[["c_cntin"]][[length(e[["c_cntin"]]) + 1]] <- list(y = y, 
        z = z, l = l, h = h)
    .Call("_cgAUC_c_cntin", PACKAGE = "cgAUC", y, z, l, h)
}
