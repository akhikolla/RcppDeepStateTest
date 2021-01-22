function (a, b, kern, other_a, other_b, other_kern) 
{
    e <- get("data.env", .GlobalEnv)
    e[["quadProd"]][[length(e[["quadProd"]]) + 1]] <- list(a = a, 
        b = b, kern = kern, other_a = other_a, other_b = other_b, 
        other_kern = other_kern)
    .Call("_cort_quadProd", a, b, kern, other_a, other_b, other_kern)
}
