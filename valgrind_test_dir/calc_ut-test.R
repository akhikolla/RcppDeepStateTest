function (jd_ut, ipl, iflag) 
{
    e <- get("data.env", .GlobalEnv)
    e[["calc_ut"]][[length(e[["calc_ut"]]) + 1]] <- list(jd_ut = jd_ut, 
        ipl = ipl, iflag = iflag)
    .Call("_swephR_calc_ut", jd_ut, ipl, iflag)
}
