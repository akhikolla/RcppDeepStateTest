function (fam, y, ppp, par1, par2) 
{
    e <- get("data.env", .GlobalEnv)
    e[["rcpp_dmix"]][[length(e[["rcpp_dmix"]]) + 1]] <- list(fam = fam, 
        y = y, ppp = ppp, par1 = par1, par2 = par2)
    .Call("_NHMM_rcpp_dmix", fam, y, ppp, par1, par2)
}
