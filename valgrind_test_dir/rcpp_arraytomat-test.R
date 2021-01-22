function (arr3d, c, A, B, C) 
{
    e <- get("data.env", .GlobalEnv)
    e[["rcpp_arraytomat"]][[length(e[["rcpp_arraytomat"]]) + 
        1]] <- list(arr3d = arr3d, c = c, A = A, B = B, C = C)
    .Call("_NHMM_rcpp_arraytomat", arr3d, c, A, B, C)
}
