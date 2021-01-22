function (wic) 
{
    e <- get("data.env", .GlobalEnv)
    e[["rcpp_calculate_vic"]][[length(e[["rcpp_calculate_vic"]]) + 
        1]] <- list(wic = wic)
    .Call("_disclapmix_rcpp_calculate_vic", PACKAGE = "disclapmix", 
        wic)
}
