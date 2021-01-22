function (s0, s1, time0, time1, time, delta, trt, tau) 
{
    e <- get("data.env", .GlobalEnv)
    e[["hhgsurv_test_stat"]][[length(e[["hhgsurv_test_stat"]]) + 
        1]] <- list(s0 = s0, s1 = s1, time0 = time0, time1 = time1, 
        time = time, delta = delta, trt = trt, tau = tau)
    .Call("_KONPsurv_hhgsurv_test_stat", PACKAGE = "KONPsurv", 
        s0, s1, time0, time1, time, delta, trt, tau)
}
