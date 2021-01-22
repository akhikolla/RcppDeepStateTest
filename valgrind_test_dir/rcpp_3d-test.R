function (jf, kf, lf, Jf, Kf, Lf) 
{
    e <- get("data.env", .GlobalEnv)
    e[["rcpp_3d"]][[length(e[["rcpp_3d"]]) + 1]] <- list(jf = jf, 
        kf = kf, lf = lf, Jf = Jf, Kf = Kf, Lf = Lf)
    .Call("_NHMM_rcpp_3d", jf, kf, lf, Jf, Kf, Lf)
}
