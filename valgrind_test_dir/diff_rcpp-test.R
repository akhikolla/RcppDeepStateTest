function (xs) 
{
    e <- get("data.env", .GlobalEnv)
    e[["diff_rcpp"]][[length(e[["diff_rcpp"]]) + 1]] <- list(xs = xs)
    .Call("_amt_diff_rcpp", PACKAGE = "amt", xs)
}
