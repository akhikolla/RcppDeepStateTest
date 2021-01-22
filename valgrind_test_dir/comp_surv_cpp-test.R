function (time1, event1, time0, event0) 
{
    e <- get("data.env", .GlobalEnv)
    e[["comp_surv_cpp"]][[length(e[["comp_surv_cpp"]]) + 1]] <- list(time1 = time1, 
        event1 = event1, time0 = time0, event0 = event0)
    .Call("_WinRatio_comp_surv_cpp", time1, event1, time0, event0)
}
