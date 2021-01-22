function (element, vector) 
{
    e <- get("data.env", .GlobalEnv)
    e[["in_rcpp"]][[length(e[["in_rcpp"]]) + 1]] <- list(element = element, 
        vector = vector)
    .Call("_bnclassify_in_rcpp", PACKAGE = "bnclassify", element, 
        vector)
}
