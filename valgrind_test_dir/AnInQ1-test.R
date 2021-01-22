function (knot) 
{
    e <- get("data.env", .GlobalEnv)
    e[["AnInQ1"]][[length(e[["AnInQ1"]]) + 1]] <- list(knot = knot)
    .Call("_bsplinePsd_AnInQ1", knot)
}
