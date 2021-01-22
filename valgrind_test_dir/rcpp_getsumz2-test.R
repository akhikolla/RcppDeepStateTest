function (llf, LLf, Kf, Jf, Tf, zf, Sigmainvf, in2f, yf, betaemf, 
    betaem0f) 
{
    e <- get("data.env", .GlobalEnv)
    e[["rcpp_getsumz2"]][[length(e[["rcpp_getsumz2"]]) + 1]] <- list(llf = llf, 
        LLf = LLf, Kf = Kf, Jf = Jf, Tf = Tf, zf = zf, Sigmainvf = Sigmainvf, 
        in2f = in2f, yf = yf, betaemf = betaemf, betaem0f = betaem0f)
    .Call("_NHMM_rcpp_getsumz2", llf, LLf, Kf, Jf, Tf, zf, Sigmainvf, 
        in2f, yf, betaemf, betaem0f)
}
