function (P, r, mu, s) 
{
    e <- get("data.env", .GlobalEnv)
    e[["EHI_2d_wrap_Rcpp"]][[length(e[["EHI_2d_wrap_Rcpp"]]) + 
        1]] <- list(P = P, r = r, mu = mu, s = s)
    .Call("_GPareto_EHI_2d_wrap_Rcpp", P, r, mu, s)
}
