function (A, dA, B, p) 
{
    e <- get("data.env", .GlobalEnv)
    e[["rcpp_gkronDBS"]][[length(e[["rcpp_gkronDBS"]]) + 1]] <- list(A = A, 
        dA = dA, B = B, p = p)
    .Call("_CGGP_rcpp_gkronDBS", PACKAGE = "CGGP", A, dA, B, 
        p)
}
