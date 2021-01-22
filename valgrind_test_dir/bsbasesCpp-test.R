function (xs, kns, order) 
{
    e <- get("data.env", .GlobalEnv)
    e[["bsbasesCpp"]][[length(e[["bsbasesCpp"]]) + 1]] <- list(xs = xs, 
        kns = kns, order = order)
    .Call("_ibs_bsbasesCpp", xs, kns, order)
}
