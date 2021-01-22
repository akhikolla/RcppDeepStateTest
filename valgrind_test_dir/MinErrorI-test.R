function (data) 
{
    e <- get("data.env", .GlobalEnv)
    e[["MinErrorI"]][[length(e[["MinErrorI"]]) + 1]] <- list(data = data)
    .Call("_autothresholdr_MinErrorI", data)
}
