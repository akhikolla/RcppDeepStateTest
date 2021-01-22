function (n, f, nV) 
{
    e <- get("data.env", .GlobalEnv)
    e[["CreateHexaSubfaces_"]][[length(e[["CreateHexaSubfaces_"]]) + 
        1]] <- list(n = n, f = f, nV = nV)
    .Call("_icosa_CreateHexaSubfaces_", n, f, nV)
}
