function () 
{
    e <- get("data.env", .GlobalEnv)
    e[["temp2SVP"]][[length(e[["temp2SVP"]]) + 1]] <- list()
    list(NULL, character(0))
}
