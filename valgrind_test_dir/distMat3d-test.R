function (x, y, z, power = 2L) 
{
    e <- get("data.env", .GlobalEnv)
    e[["distMat3d"]][[length(e[["distMat3d"]]) + 1]] <- list(x = x, 
        y = y, z = z, power = power)
    .Call("_mousetrap_distMat3d", x, y, z, power)
}
