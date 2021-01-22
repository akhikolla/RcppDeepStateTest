function (a, b, t, ct) 
{
    e <- get("data.env", .GlobalEnv)
    e[["w_ij_cpp"]][[length(e[["w_ij_cpp"]]) + 1]] <- list(a = a, 
        b = b, t = t, ct = ct)
    .Call("_activegp_w_ij_cpp", PACKAGE = "activegp", a, b, t, 
        ct)
}
