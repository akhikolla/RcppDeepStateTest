function () 
{
    e <- get("data.env", .GlobalEnv)
    e[["point_in_polygon"]][[length(e[["point_in_polygon"]]) + 
        1]] <- list()
    list(NULL, character(0))
}
