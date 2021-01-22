function (data) 
{
    e <- get("data.env", .GlobalEnv)
    e[["Yen"]][[length(e[["Yen"]]) + 1]] <- list(data = data)
    .Call("_autothresholdr_Yen", data)
}
