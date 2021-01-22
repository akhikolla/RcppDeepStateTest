function (x, exp, n) 
{
    e <- get("data.env", .GlobalEnv)
    e[["inputRow"]][[length(e[["inputRow"]]) + 1]] <- list(x = x, 
        exp = exp, n = n)
    .Call("_NAM_inputRow", x, exp, n)
}
