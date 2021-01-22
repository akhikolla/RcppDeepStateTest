function (starname, jd_et, iflag) 
{
    e <- get("data.env", .GlobalEnv)
    e[["fixstar2"]][[length(e[["fixstar2"]]) + 1]] <- list(starname = starname, 
        jd_et = jd_et, iflag = iflag)
    .Call("_swephR_fixstar2", starname, jd_et, iflag)
}
