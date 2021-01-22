function (x, y, method, max_dim, screen) 
{
    e <- get("data.env", .GlobalEnv)
    e[["MAVEfastCpp"]][[length(e[["MAVEfastCpp"]]) + 1]] <- list(x = x, 
        y = y, method = method, max_dim = max_dim, screen = screen)
    .Call("_MAVE_MAVEfastCpp", PACKAGE = "MAVE", x, y, method, 
        max_dim, screen)
}
