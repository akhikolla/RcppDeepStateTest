function (A, B, p) 
{
    e <- get("data.env", .GlobalEnv)
    e[["rcpp_kronDBS"]][[length(e[["rcpp_kronDBS"]]) + 1]] <- list(A = A, 
        B = B, p = p)
    invisible(c(".Call", "_CGGP_rcpp_kronDBS", "CGGP", "A", "B", 
    "p"))
}
