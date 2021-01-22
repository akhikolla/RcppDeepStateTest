function (x1, y1, x2, y2, x0, y0, eps = 1e-16) 
{
    e <- get("data.env", .GlobalEnv)
    e[["on"]][[length(e[["on"]]) + 1]] <- list(x1 = x1, y1 = y1, 
        x2 = x2, y2 = y2, x0 = x0, y0 = y0, eps = eps)
    .Call("_interp_on", PACKAGE = "interp", x1, y1, x2, y2, x0, 
        y0, eps)
}
