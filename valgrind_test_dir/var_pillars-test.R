function (arr3d) 
{
    e <- get("data.env", .GlobalEnv)
    e[["var_pillars"]][[length(e[["var_pillars"]]) + 1]] <- list(arr3d = arr3d)
    .Call("_autothresholdr_var_pillars", arr3d)
}
