function () 
{
    e <- get("data.env", .GlobalEnv)
    e[["PenmanMonteithPET"]][[length(e[["PenmanMonteithPET"]]) + 
        1]] <- list()
    list(NULL, character(0))
}
