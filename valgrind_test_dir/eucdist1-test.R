function (x, y, eps) 
{
    e <- get("data.env", .GlobalEnv)
    e[["eucdist1"]][[length(e[["eucdist1"]]) + 1]] <- list(x = x, 
        y = y, eps = eps)
    .Call("_gear_eucdist1", x, y, eps)
}
