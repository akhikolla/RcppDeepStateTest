function (data) 
{
    e <- get("data.env", .GlobalEnv)
    e[["IJDefault"]][[length(e[["IJDefault"]]) + 1]] <- list(data = data)
    .Call("_autothresholdr_IJDefault", data)
}
