function (a, b, t, ct) 
{
    e <- get("data.env", .GlobalEnv)
    e[["grad_Ikk_cppb"]][[length(e[["grad_Ikk_cppb"]]) + 1]] <- list(a = a, 
        b = b, t = t, ct = ct)
    .Call("_activegp_grad_Ikk_cppb", PACKAGE = "activegp", a, 
        b, t, ct)
}
