function (t, x, y, period, tol) 
{
    e <- get("data.env", .GlobalEnv)
    e[["track_immobility"]][[length(e[["track_immobility"]]) + 
        1]] <- list(t = t, x = x, y = y, period = period, tol = tol)
    .Call("_amt_track_immobility", PACKAGE = "amt", t, x, y, 
        period, tol)
}
