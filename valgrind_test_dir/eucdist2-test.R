function (x1, y1, x2, y2, eps) 
{
    e <- get("data.env", .GlobalEnv)
    e[["eucdist2"]][[length(e[["eucdist2"]]) + 1]] <- list(x1 = x1, 
        y1 = y1, x2 = x2, y2 = y2, eps = eps)
    .Call("_gear_eucdist2", x1, y1, x2, y2, eps)
}
