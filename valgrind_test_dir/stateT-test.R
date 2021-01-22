function (origin, newstates, cumuprobs, sMatrix) 
{
    e <- get("data.env", .GlobalEnv)
    e[["stateT"]][[length(e[["stateT"]]) + 1]] <- list(origin = origin, 
        newstates = newstates, cumuprobs = cumuprobs, sMatrix = sMatrix)
    .Call("_ibmcraftr_stateT", PACKAGE = "ibmcraftr", origin, 
        newstates, cumuprobs, sMatrix)
}
