function (x, command, nCommands) 
{
    e <- get("data.env", .GlobalEnv)
    e[["extractMandatory"]][[length(e[["extractMandatory"]]) + 
        1]] <- list(x = x, command = command, nCommands = nCommands)
    .Call("_hutilscpp_extractMandatory", x, command, nCommands)
}
