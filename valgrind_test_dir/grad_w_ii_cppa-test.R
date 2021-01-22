function (a, b, t, ct) 
{
    e <- get("data.env", .GlobalEnv)
    e[["grad_w_ii_cppa"]][[length(e[["grad_w_ii_cppa"]]) + 1]] <- list(a = a, 
        b = b, t = t, ct = ct)
    .Call("_activegp_grad_w_ii_cppa", PACKAGE = "activegp", a, 
        b, t, ct)
}
