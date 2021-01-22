function (deg) 
{
    e <- get("data.env", .GlobalEnv)
    e[["deg2rad"]][[length(e[["deg2rad"]]) + 1]] <- list(deg = deg)
    .Call("_Rvoterdistance_deg2rad", deg)
}
