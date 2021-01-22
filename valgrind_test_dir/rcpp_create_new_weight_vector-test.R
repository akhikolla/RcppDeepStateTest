function (vic, loci) 
{
    e <- get("data.env", .GlobalEnv)
    e[["rcpp_create_new_weight_vector"]][[length(e[["rcpp_create_new_weight_vector"]]) + 
        1]] <- list(vic = vic, loci = loci)
    .Call("_disclapmix_rcpp_create_new_weight_vector", PACKAGE = "disclapmix", 
        vic, loci)
}
