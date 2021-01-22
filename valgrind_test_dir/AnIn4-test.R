function (knot) 
{
    e <- get("data.env", .GlobalEnv)
    e[["AnIn4"]][[length(e[["AnIn4"]]) + 1]] <- list(knot = knot)
    .Call("_bsplinePsd_AnIn4", knot)
}
