function (data) 
{
    e <- get("data.env", .GlobalEnv)
    e[["Percentile"]][[length(e[["Percentile"]]) + 1]] <- list(data = data)
    .Call("_autothresholdr_Percentile", data)
}
