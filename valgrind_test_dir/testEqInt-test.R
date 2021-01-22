function (x, y) 
{
    e <- get("data.env", .GlobalEnv)
    e[["testEqInt"]][[length(e[["testEqInt"]]) + 1]] <- list(x = x, 
        y = y)
    .Call("_phylobase_testEqInt", x, y)
}
