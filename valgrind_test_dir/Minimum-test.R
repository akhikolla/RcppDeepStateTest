function (data) 
{
    e <- get("data.env", .GlobalEnv)
    e[["Minimum"]][[length(e[["Minimum"]]) + 1]] <- list(data = data)
    .Call("_autothresholdr_Minimum", data)
}
