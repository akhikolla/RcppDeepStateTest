function (n) 
{
    e <- get("data.env", .GlobalEnv)
    e[["start_matrix"]][[length(e[["start_matrix"]]) + 1]] <- list(n = n)
    .Call("_bartBMA_start_matrix", n)
}
