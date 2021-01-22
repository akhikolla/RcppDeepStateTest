function () 
{
    e <- get("data.env", .GlobalEnv)
    e[["fixstar2_mag"]][[length(e[["fixstar2_mag"]]) + 1]] <- list()
    list(NULL, character(0))
}
