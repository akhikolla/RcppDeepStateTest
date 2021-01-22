function (dn) 
{
    e <- get("data.env", .GlobalEnv)
    e[["set_tracer_on"]][[length(e[["set_tracer_on"]]) + 1]] <- list(dn = dn)
    .Call("_ggiraph_set_tracer_on", dn)
}
