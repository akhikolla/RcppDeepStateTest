function (S, x1, x2) 
{
    e <- get("data.env", .GlobalEnv)
    e[["hvolume2d_Rcpp"]][[length(e[["hvolume2d_Rcpp"]]) + 1]] <- list(S = S, 
        x1 = x1, x2 = x2)
    .Call("_GPareto_hvolume2d_Rcpp", S, x1, x2)
}
