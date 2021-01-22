function (rate, n_rank) 
{
    e <- get("data.env", .GlobalEnv)
    e[["SimYpsilon"]][[length(e[["SimYpsilon"]]) + 1]] <- list(rate = rate, 
        n_rank = n_rank)
    .Call("_PLMIX_SimYpsilon", rate, n_rank)
}
