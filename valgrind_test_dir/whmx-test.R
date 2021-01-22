function (vettore) 
{
    e <- get("data.env", .GlobalEnv)
    e[["whmx"]][[length(e[["whmx"]]) + 1]] <- list(vettore = vettore)
    .Call("_GeDS_whmx", PACKAGE = "GeDS", vettore)
}
