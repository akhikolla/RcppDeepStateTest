function (repnum, n, B1inq, xi1d, xi2d, cids1, cids2) 
{
    e <- get("data.env", .GlobalEnv)
    e[["ransamf"]][[length(e[["ransamf"]]) + 1]] <- list(repnum = repnum, 
        n = n, B1inq = B1inq, xi1d = xi1d, xi2d = xi2d, cids1 = cids1, 
        cids2 = cids2)
    .Call("_ClinicalTrialSummary_ransamf", PACKAGE = "ClinicalTrialSummary", 
        repnum, n, B1inq, xi1d, xi2d, cids1, cids2)
}
