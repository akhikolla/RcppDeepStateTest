function (fam, ppp, par1, par2) 
{
    e <- get("data.env", .GlobalEnv)
    e[["rcpp_rmix"]][[length(e[["rcpp_rmix"]]) + 1]] <- list(fam = fam, 
        ppp = ppp, par1 = par1, par2 = par2)
    .Call("_NHMM_rcpp_rmix", fam, ppp, par1, par2)
}
