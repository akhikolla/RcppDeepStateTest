function (data) 
{
    e <- get("data.env", .GlobalEnv)
    e[["Huang"]][[length(e[["Huang"]]) + 1]] <- list(data = data)
    .Call("_autothresholdr_Huang", data)
}
