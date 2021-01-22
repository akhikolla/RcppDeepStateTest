function (a, b) 
{
    e <- get("data.env", .GlobalEnv)
    e[["is_equal_mindist"]][[length(e[["is_equal_mindist"]]) + 
        1]] <- list(a = a, b = b)
    .Call("_jmotif_is_equal_mindist", PACKAGE = "jmotif", a, 
        b)
}
