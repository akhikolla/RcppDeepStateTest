function (x3d, y3d) 
{
    e <- get("data.env", .GlobalEnv)
    e[["cross_var_pillars_Cpp"]][[length(e[["cross_var_pillars_Cpp"]]) + 
        1]] <- list(x3d = x3d, y3d = y3d)
    .Call("_nandb_cross_var_pillars_Cpp", x3d, y3d)
}
