function (AR, BR, threads) 
{
    e <- get("data.env", .GlobalEnv)
    e[["gen_cost"]][[length(e[["gen_cost"]]) + 1]] <- list(AR = AR, 
        BR = BR, threads = threads)
    .Call("_transport_gen_cost", AR, BR, threads)
}
