function (x, y, power = 2L) 
{
    e <- get("data.env", .GlobalEnv)
    e[["distMat"]][[length(e[["distMat"]]) + 1]] <- list(x = x, 
        y = y, power = power)
    .Call("_mousetrap_distMat", x, y, power)
}
