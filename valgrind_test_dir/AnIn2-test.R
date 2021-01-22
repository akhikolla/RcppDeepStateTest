function (knot) 
{
    e <- get("data.env", .GlobalEnv)
    e[["AnIn2"]][[length(e[["AnIn2"]]) + 1]] <- list(knot = knot)
    .Call("_bsplinePsd_AnIn2", knot)
}
