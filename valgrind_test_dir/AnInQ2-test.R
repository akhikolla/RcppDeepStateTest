function (knot) 
{
    e <- get("data.env", .GlobalEnv)
    e[["AnInQ2"]][[length(e[["AnInQ2"]]) + 1]] <- list(knot = knot)
    .Call("_bsplinePsd_AnInQ2", knot)
}
