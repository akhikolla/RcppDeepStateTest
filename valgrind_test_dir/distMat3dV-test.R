function (x, y, z, power = 2L) 
{
    e <- get("data.env", .GlobalEnv)
    e[["distMat3dV"]][[length(e[["distMat3dV"]]) + 1]] <- list(x = x, 
        y = y, z = z, power = power)
    .Call("_mousetrap_distMat3dV", x, y, z, power)
}
