function (knot) 
{
    e <- get("data.env", .GlobalEnv)
    e[["AnIn6"]][[length(e[["AnIn6"]]) + 1]] <- list(knot = knot)
    .Call("_bsplinePsd_AnIn6", knot)
}
