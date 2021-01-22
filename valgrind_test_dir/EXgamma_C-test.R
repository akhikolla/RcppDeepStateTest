function (data, alpha, lambda) 
{
    e <- get("data.env", .GlobalEnv)
    e[["EXgamma_C"]][[length(e[["EXgamma_C"]]) + 1]] <- list(data = data, 
        alpha = alpha, lambda = lambda)
    .Call("_mixR_EXgamma_C", data, alpha, lambda)
}
