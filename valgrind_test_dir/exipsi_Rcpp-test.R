function (a, b, m, s) 
{
    e <- get("data.env", .GlobalEnv)
    e[["exipsi_Rcpp"]][[length(e[["exipsi_Rcpp"]]) + 1]] <- list(a = a, 
        b = b, m = m, s = s)
    .Call("_GPareto_exipsi_Rcpp", a, b, m, s)
}
