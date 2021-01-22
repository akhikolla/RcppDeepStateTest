function (a, b, t, ct) 
{
    e <- get("data.env", .GlobalEnv)
    e[["Ikk_cpp"]][[length(e[["Ikk_cpp"]]) + 1]] <- list(a = a, 
        b = b, t = t, ct = ct)
    .Call("_activegp_Ikk_cpp", PACKAGE = "activegp", a, b, t, 
        ct)
}
