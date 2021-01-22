function (knot) 
{
    e <- get("data.env", .GlobalEnv)
    e[["AnInQ4"]][[length(e[["AnInQ4"]]) + 1]] <- list(knot = knot)
    .Call("_bsplinePsd_AnInQ4", knot)
}
