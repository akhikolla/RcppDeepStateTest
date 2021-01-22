function (a, b, p) 
{
    e <- get("data.env", .GlobalEnv)
    e[["bivRho"]][[length(e[["bivRho"]]) + 1]] <- list(a = a, 
        b = b, p = p)
    .Call("_cort_bivRho", a, b, p)
}
