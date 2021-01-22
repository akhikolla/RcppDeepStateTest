function (nT, xT, yT, i1, i2, i3, x, y) 
{
    e <- get("data.env", .GlobalEnv)
    e[["triFind"]][[length(e[["triFind"]]) + 1]] <- list(nT = nT, 
        xT = xT, yT = yT, i1 = i1, i2 = i2, i3 = i3, x = x, y = y)
    .Call("_interp_triFind", PACKAGE = "interp", nT, xT, yT, 
        i1, i2, i3, x, y)
}
