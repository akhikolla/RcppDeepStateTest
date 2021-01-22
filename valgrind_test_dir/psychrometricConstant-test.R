function () 
{
    e <- get("data.env", .GlobalEnv)
    e[["psychrometricConstant"]][[length(e[["psychrometricConstant"]]) + 
        1]] <- list()
    list(NULL, character(0))
}
