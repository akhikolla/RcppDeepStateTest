function (starname, jd_ut, iflag) 
{
    e <- get("data.env", .GlobalEnv)
    e[["fixstar2_ut"]][[length(e[["fixstar2_ut"]]) + 1]] <- list(starname = starname, 
        jd_ut = jd_ut, iflag = iflag)
    .Call("_swephR_fixstar2_ut", starname, jd_ut, iflag)
}
