function (q) 
{
    e <- get("data.env", .GlobalEnv)
    e[["xyz1"]][[length(e[["xyz1"]]) + 1]] <- list(q = q)
    .Call("_icosa_xyz1", q)
}
