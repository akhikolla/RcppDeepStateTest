function (param, numbuys, numsells) 
{
    e <- get("data.env", .GlobalEnv)
    e[["eho"]][[length(e[["eho"]]) + 1]] <- list(param = param, 
        numbuys = numbuys, numsells = numsells)
    .Call("_pinbasic_eho", PACKAGE = "pinbasic", param, numbuys, 
        numsells)
}
