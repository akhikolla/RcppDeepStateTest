function (data) 
{
    e <- get("data.env", .GlobalEnv)
    e[["Huang2"]][[length(e[["Huang2"]]) + 1]] <- list(data = data)
    .Call("_autothresholdr_Huang2", data)
}
