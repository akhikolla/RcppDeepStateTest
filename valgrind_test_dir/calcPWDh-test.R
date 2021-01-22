function (x) 
{
    e <- get("data.env", .GlobalEnv)
    e[["calcPWDh"]][[length(e[["calcPWDh"]]) + 1]] <- list(x = x)
    .Call("_redist_calcPWDh", x)
}
