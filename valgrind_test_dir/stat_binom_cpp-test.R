function (yin, yout, ty, popin, popout, tpop) 
{
    e <- get("data.env", .GlobalEnv)
    e[["stat_binom_cpp"]][[length(e[["stat_binom_cpp"]]) + 1]] <- list(yin = yin, 
        yout = yout, ty = ty, popin = popin, popout = popout, 
        tpop = tpop)
    .Call("_smerc_stat_binom_cpp", yin, yout, ty, popin, popout, 
        tpop)
}
