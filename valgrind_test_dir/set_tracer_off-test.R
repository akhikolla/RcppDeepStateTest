function (dn) 
{
    e <- get("data.env", .GlobalEnv)
    e[["set_tracer_off"]][[length(e[["set_tracer_off"]]) + 1]] <- list(dn = dn)
    .Call("_ggiraph_set_tracer_off", dn)
}
