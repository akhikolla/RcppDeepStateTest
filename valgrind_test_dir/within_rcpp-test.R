function (x, a, b) 
{
    e <- get("data.env", .GlobalEnv)
    e[["within_rcpp"]][[length(e[["within_rcpp"]]) + 1]] <- list(x = x, 
        a = a, b = b)
    .Call("_amt_within_rcpp", PACKAGE = "amt", x, a, b)
}
