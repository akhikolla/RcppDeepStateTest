function (time, event, stime, Zc, D_status, eps_2, Zc_dot) 
{
    e <- get("data.env", .GlobalEnv)
    e[["ivsacim_est"]][[length(e[["ivsacim_est"]]) + 1]] <- list(time = time, 
        event = event, stime = stime, Zc = Zc, D_status = D_status, 
        eps_2 = eps_2, Zc_dot = Zc_dot)
    .Call("_ivsacim_ivsacim_est", time, event, stime, Zc, D_status, 
        eps_2, Zc_dot)
}
