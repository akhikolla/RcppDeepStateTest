function (time1, event1, fu1, time0, event0, fu0) 
{
    e <- get("data.env", .GlobalEnv)
    e[["comp_repeated_cpp"]][[length(e[["comp_repeated_cpp"]]) + 
        1]] <- list(time1 = time1, event1 = event1, fu1 = fu1, 
        time0 = time0, event0 = event0, fu0 = fu0)
    .Call("_WinRatio_comp_repeated_cpp", time1, event1, fu1, 
        time0, event0, fu0)
}
