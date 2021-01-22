function (data) 
{
    e <- get("data.env", .GlobalEnv)
    e[["Otsu"]][[length(e[["Otsu"]]) + 1]] <- list(data = data)
    .Call("_autothresholdr_Otsu", data)
}
