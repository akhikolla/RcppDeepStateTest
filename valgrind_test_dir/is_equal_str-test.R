function (a, b) 
{
    e <- get("data.env", .GlobalEnv)
    e[["is_equal_str"]][[length(e[["is_equal_str"]]) + 1]] <- list(a = a, 
        b = b)
    .Call("_jmotif_is_equal_str", PACKAGE = "jmotif", a, b)
}
