function (v, f) 
{
    e <- get("data.env", .GlobalEnv)
    e[["xyz1xyz1xyz1xyz1_"]][[length(e[["xyz1xyz1xyz1xyz1_"]]) + 
        1]] <- list(v = v, f = f)
    .Call("_icosa_xyz1xyz1xyz1xyz1_", v, f)
}
