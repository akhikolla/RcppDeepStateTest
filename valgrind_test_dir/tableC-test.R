function (x) 
{
    e <- get("data.env", .GlobalEnv)
    e[["tableC"]][[length(e[["tableC"]]) + 1]] <- list(x = x)
    .Call("_simPop_tableC", PACKAGE = "simPop", x)
}
