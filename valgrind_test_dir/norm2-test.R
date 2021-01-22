function (x) 
{
    e <- get("data.env", .GlobalEnv)
    e[["norm2"]][[length(e[["norm2"]]) + 1]] <- list(x = x)
    .Call("_BigVAR_norm2", x)
}
