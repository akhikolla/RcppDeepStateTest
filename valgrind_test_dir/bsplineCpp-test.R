function (xs, ord, kns, coef) 
{
    e <- get("data.env", .GlobalEnv)
    e[["bsplineCpp"]][[length(e[["bsplineCpp"]]) + 1]] <- list(xs = xs, 
        ord = ord, kns = kns, coef = coef)
    .Call("_ibs_bsplineCpp", xs, ord, kns, coef)
}
