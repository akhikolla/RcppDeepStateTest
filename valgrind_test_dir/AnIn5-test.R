function (knot) 
{
    e <- get("data.env", .GlobalEnv)
    e[["AnIn5"]][[length(e[["AnIn5"]]) + 1]] <- list(knot = knot)
    .Call("_bsplinePsd_AnIn5", knot)
}
