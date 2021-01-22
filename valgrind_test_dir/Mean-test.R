function (data) 
{
    e <- get("data.env", .GlobalEnv)
    e[["Mean"]][[length(e[["Mean"]]) + 1]] <- list(data = data)
    .Call("_autothresholdr_Mean", data)
}
