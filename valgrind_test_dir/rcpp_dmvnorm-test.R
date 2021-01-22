function (dataf, meanf, Siginvf, detf) 
{
    e <- get("data.env", .GlobalEnv)
    e[["rcpp_dmvnorm"]][[length(e[["rcpp_dmvnorm"]]) + 1]] <- list(dataf = dataf, 
        meanf = meanf, Siginvf = Siginvf, detf = detf)
    .Call("_NHMM_rcpp_dmvnorm", dataf, meanf, Siginvf, detf)
}
