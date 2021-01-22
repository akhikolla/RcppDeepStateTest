function (inputTheta, phi, verbose) 
{
    e <- get("data.env", .GlobalEnv)
    e[["solveODE"]][[length(e[["solveODE"]]) + 1]] <- list(inputTheta = inputTheta, 
        phi = phi, verbose = verbose)
    .Call("_abcADM_solveODE", inputTheta, phi, verbose)
}
