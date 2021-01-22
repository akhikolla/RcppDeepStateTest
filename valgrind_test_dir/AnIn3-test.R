function (knot) 
{
    e <- get("data.env", .GlobalEnv)
    e[["AnIn3"]][[length(e[["AnIn3"]]) + 1]] <- list(knot = knot)
    .Call("_bsplinePsd_AnIn3", knot)
}
