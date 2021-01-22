function (t1, nt, time_tol, type) 
{
    e <- get("data.env", .GlobalEnv)
    e[["track_align_cpp"]][[length(e[["track_align_cpp"]]) + 
        1]] <- list(t1 = t1, nt = nt, time_tol = time_tol, type = type)
    .Call("_amt_track_align_cpp", PACKAGE = "amt", t1, nt, time_tol, 
        type)
}
