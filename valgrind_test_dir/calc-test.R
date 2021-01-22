function (jd_et, ipl, iflag) 
{
    e <- get("data.env", .GlobalEnv)
    e[["calc"]][[length(e[["calc"]]) + 1]] <- list(jd_et = jd_et, 
        ipl = ipl, iflag = iflag)
    .Call("_swephR_calc", jd_et, ipl, iflag)
}
