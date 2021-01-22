function (x, y) 
{
    e <- get("data.env", .GlobalEnv)
    e[["crossover"]][[length(e[["crossover"]]) + 1]] <- list(x = x, 
        y = y)
    .Call("_QuantTools_crossover", x, y)
}
