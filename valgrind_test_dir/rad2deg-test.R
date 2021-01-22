function (rad) 
{
    e <- get("data.env", .GlobalEnv)
    e[["rad2deg"]][[length(e[["rad2deg"]]) + 1]] <- list(rad = rad)
    .Call("_Rvoterdistance_rad2deg", rad)
}
