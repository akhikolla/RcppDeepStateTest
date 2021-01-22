function (a, muf, sigf, lowf, upf, boolowf, booupf) 
{
    e <- get("data.env", .GlobalEnv)
    e[["Crtnorm"]][[length(e[["Crtnorm"]]) + 1]] <- list(a = a, 
        muf = muf, sigf = sigf, lowf = lowf, upf = upf, boolowf = boolowf, 
        booupf = booupf)
    .Call("_NHMM_Crtnorm", a, muf, sigf, lowf, upf, boolowf, 
        booupf)
}
