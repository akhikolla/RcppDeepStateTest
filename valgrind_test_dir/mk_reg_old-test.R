function (relocs_time, time_dist, time_tol, start) 
{
    e <- get("data.env", .GlobalEnv)
    e[["mk_reg_old"]][[length(e[["mk_reg_old"]]) + 1]] <- list(relocs_time = relocs_time, 
        time_dist = time_dist, time_tol = time_tol, start = start)
    .Call("_amt_mk_reg_old", PACKAGE = "amt", relocs_time, time_dist, 
        time_tol, start)
}
