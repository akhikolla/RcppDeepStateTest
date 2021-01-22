function () 
{
    e <- get("data.env", .GlobalEnv)
    e[["lun_eclipse_how"]][[length(e[["lun_eclipse_how"]]) + 
        1]] <- list()
    list(NULL, character(0))
}
