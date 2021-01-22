function (zf, QQf, denzity, subseqy) 
{
    e <- get("data.env", .GlobalEnv)
    e[["rcpp_getz"]][[length(e[["rcpp_getz"]]) + 1]] <- list(zf = zf, 
        QQf = QQf, denzity = denzity, subseqy = subseqy)
    invisible(c(".Call", "'_NHMM_rcpp_getz`", "zf", "QQf", "denzity", 
    "subseqy"))
}
