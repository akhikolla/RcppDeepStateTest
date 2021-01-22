function (x, y, gamma, P) 
{
    e <- get("data.env", .GlobalEnv)
    e[["alasso"]][[length(e[["alasso"]]) + 1]] <- list(x = x, 
        y = y, gamma = gamma, P = P)
    .Call("_dfphase1_alasso", PACKAGE = "dfphase1", x, y, gamma, 
        P)
}
