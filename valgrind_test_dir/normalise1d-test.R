function (vec, pnorm = 2L) 
{
    e <- get("data.env", .GlobalEnv)
    e[["normalise1d"]][[length(e[["normalise1d"]]) + 1]] <- list(vec = vec, 
        pnorm = pnorm)
    .Call("_superml_normalise1d", PACKAGE = "superml", vec, pnorm)
}
