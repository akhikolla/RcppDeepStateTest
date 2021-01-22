function (Kf, Jf, Tf, zf, Sigmainvf, in2f) 
{
    e <- get("data.env", .GlobalEnv)
    e[["rcpp_getsumz1"]][[length(e[["rcpp_getsumz1"]]) + 1]] <- list(Kf = Kf, 
        Jf = Jf, Tf = Tf, zf = zf, Sigmainvf = Sigmainvf, in2f = in2f)
    .Call("_NHMM_rcpp_getsumz1", Kf, Jf, Tf, zf, Sigmainvf, in2f)
}
