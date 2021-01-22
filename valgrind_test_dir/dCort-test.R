function (a, b, kern, u) 
{
    e <- get("data.env", .GlobalEnv)
    e[["dCort"]][[length(e[["dCort"]]) + 1]] <- list(a = a, b = b, 
        kern = kern, u = u)
    .Call("_cort_dCort", a, b, kern, u)
}
