function (x, val1, val2) 
{
    e <- get("data.env", .GlobalEnv)
    e[["select_equal"]][[length(e[["select_equal"]]) + 1]] <- list(x = x, 
        val1 = val1, val2 = val2)
    .Call("_simPop_select_equal", PACKAGE = "simPop", x, val1, 
        val2)
}
