function () 
{
    e <- get("data.env", .GlobalEnv)
    e[["heliacal_angle"]][[length(e[["heliacal_angle"]]) + 1]] <- list()
    list(NULL, character(0))
}
