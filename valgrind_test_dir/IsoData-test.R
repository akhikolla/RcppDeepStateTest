function (data) 
{
    e <- get("data.env", .GlobalEnv)
    e[["IsoData"]][[length(e[["IsoData"]]) + 1]] <- list(data = data)
    .Call("_autothresholdr_IsoData", data)
}
