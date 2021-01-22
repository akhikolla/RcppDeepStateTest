function (data) 
{
    e <- get("data.env", .GlobalEnv)
    e[["MaxEntropy"]][[length(e[["MaxEntropy"]]) + 1]] <- list(data = data)
    .Call("_autothresholdr_MaxEntropy", data)
}
