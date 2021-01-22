function (data) 
{
    e <- get("data.env", .GlobalEnv)
    e[["Triangle"]][[length(e[["Triangle"]]) + 1]] <- list(data = data)
    .Call("_autothresholdr_Triangle", data)
}
