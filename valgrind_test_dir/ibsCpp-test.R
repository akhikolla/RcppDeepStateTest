function (xs, ord, kns, coef) 
{
    e <- get("data.env", .GlobalEnv)
    e[["ibsCpp"]][[length(e[["ibsCpp"]]) + 1]] <- list(xs = xs, 
        ord = ord, kns = kns, coef = coef)
    .Call("_ibs_ibsCpp", xs, ord, kns, coef)
}
