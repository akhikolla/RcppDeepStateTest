function (data) 
{
    e <- get("data.env", .GlobalEnv)
    e[["Shanbhag"]][[length(e[["Shanbhag"]]) + 1]] <- list(data = data)
    .Call("_autothresholdr_Shanbhag", data)
}
