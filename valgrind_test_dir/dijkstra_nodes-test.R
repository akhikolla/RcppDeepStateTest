function (dist, src, node_costs) 
{
    e <- get("data.env", .GlobalEnv)
    e[["dijkstra_nodes"]][[length(e[["dijkstra_nodes"]]) + 1]] <- list(dist = dist, 
        src = src, node_costs = node_costs)
    .Call("_gretel_dijkstra_nodes", dist, src, node_costs)
}
