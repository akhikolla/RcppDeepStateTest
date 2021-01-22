function (data, k, lambda) 
{
    e <- get("data.env", .GlobalEnv)
    e[["EXweib_C"]][[length(e[["EXweib_C"]]) + 1]] <- list(data = data, 
        k = k, lambda = lambda)
    .Call("_mixR_EXweib_C", data, k, lambda)
}
