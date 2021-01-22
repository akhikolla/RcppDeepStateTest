function (a, b, p, u) 
{
    e <- get("data.env", .GlobalEnv)
    e[["pCort"]][[length(e[["pCort"]]) + 1]] <- list(a = a, b = b, 
        p = p, u = u)
    .Call("_cort_pCort", a, b, p, u)
}
