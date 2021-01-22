function (knot) 
{
    e <- get("data.env", .GlobalEnv)
    e[["AnIn7"]][[length(e[["AnIn7"]]) + 1]] <- list(knot = knot)
    .Call("_bsplinePsd_AnIn7", knot)
}
