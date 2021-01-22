function (x, y) 
{
    e <- get("data.env", .GlobalEnv)
    e[["cross_var_Cpp"]][[length(e[["cross_var_Cpp"]]) + 1]] <- list(x = x, 
        y = y)
    .Call("_nandb_cross_var_Cpp", x, y)
}
