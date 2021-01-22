function (a, b, C, threads) 
{
    e <- get("data.env", .GlobalEnv)
    e[["networkflow"]][[length(e[["networkflow"]]) + 1]] <- list(a = a, 
        b = b, C = C, threads = threads)
    .Call("_transport_networkflow", a, b, C, threads)
}
