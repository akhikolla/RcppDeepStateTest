function (dist, src) 
{
    e <- get("data.env", .GlobalEnv)
    e[["dijkstra_inf"]][[length(e[["dijkstra_inf"]]) + 1]] <- list(dist = dist, 
        src = src)
    .Call("_gretel_dijkstra_inf", dist, src)
}
