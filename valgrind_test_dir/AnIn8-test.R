function (knot) 
{
    e <- get("data.env", .GlobalEnv)
    e[["AnIn8"]][[length(e[["AnIn8"]]) + 1]] <- list(knot = knot)
    .Call("_bsplinePsd_AnIn8", knot)
}
