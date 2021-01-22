function (x, y, w, initial_link, i, j, skip) 
{
    e <- get("data.env", .GlobalEnv)
    e[["logistic_solve1"]][[length(e[["logistic_solve1"]]) + 
        1]] <- list(x = x, y = y, w = w, initial_link = initial_link, 
        i = i, j = j, skip = skip)
    .Call("_RcppDynProg_logistic_solve1", PACKAGE = "RcppDynProg", 
        x, y, w, initial_link, i, j, skip)
}
