function (x) 
{
    e <- get("data.env", .GlobalEnv)
    e[["mnlfa_rcpp_plogis"]][[length(e[["mnlfa_rcpp_plogis"]]) + 
        1]] <- list(x = x)
    .Call("_mnlfa_mnlfa_rcpp_plogis", PACKAGE = "mnlfa", x)
}
