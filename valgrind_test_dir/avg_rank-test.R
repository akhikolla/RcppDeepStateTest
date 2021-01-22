function (x) 
{
    e <- get("data.env", .GlobalEnv)
    e[["avg_rank"]][[length(e[["avg_rank"]]) + 1]] <- list(x = x)
    .Call("_irt_avg_rank", x)
}
