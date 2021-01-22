function (mat, pnorm = 2L, axis = 0L) 
{
    e <- get("data.env", .GlobalEnv)
    e[["normalise2d"]][[length(e[["normalise2d"]]) + 1]] <- list(mat = mat, 
        pnorm = pnorm, axis = axis)
    .Call("_superml_normalise2d", PACKAGE = "superml", mat, pnorm, 
        axis)
}
