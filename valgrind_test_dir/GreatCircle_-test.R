function (coord1, coord2, origin, breaks, pi) 
{
    e <- get("data.env", .GlobalEnv)
    e[["GreatCircle_"]][[length(e[["GreatCircle_"]]) + 1]] <- list(coord1 = coord1, 
        coord2 = coord2, origin = origin, breaks = breaks, pi = pi)
    .Call("_icosa_GreatCircle_", coord1, coord2, origin, breaks, 
        pi)
}
