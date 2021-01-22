function (a, b, p) 
{
    e <- get("data.env", .GlobalEnv)
    e[["bivTau"]][[length(e[["bivTau"]]) + 1]] <- list(a = a, 
        b = b, p = p)
    .Call("_cort_bivTau", a, b, p)
}
