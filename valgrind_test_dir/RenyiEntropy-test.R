function (data) 
{
    e <- get("data.env", .GlobalEnv)
    e[["RenyiEntropy"]][[length(e[["RenyiEntropy"]]) + 1]] <- list(data = data)
    .Call("_autothresholdr_RenyiEntropy", data)
}
