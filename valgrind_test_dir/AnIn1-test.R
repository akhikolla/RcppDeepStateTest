function (knot) 
{
    e <- get("data.env", .GlobalEnv)
    e[["AnIn1"]][[length(e[["AnIn1"]]) + 1]] <- list(knot = knot)
    .Call("_bsplinePsd_AnIn1", knot)
}
