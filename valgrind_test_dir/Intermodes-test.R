function (data) 
{
    e <- get("data.env", .GlobalEnv)
    e[["Intermodes"]][[length(e[["Intermodes"]]) + 1]] <- list(data = data)
    .Call("_autothresholdr_Intermodes", data)
}
