function (knot) 
{
    e <- get("data.env", .GlobalEnv)
    e[["AnInQ3"]][[length(e[["AnInQ3"]]) + 1]] <- list(knot = knot)
    .Call("_bsplinePsd_AnInQ3", knot)
}
