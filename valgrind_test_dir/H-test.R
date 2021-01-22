function (J, s, h) 
{
    e <- get("data.env", .GlobalEnv)
    e[["H"]][[length(e[["H"]]) + 1]] <- list(J = J, s = s, h = h)
    .Call("_IsingSampler_H", PACKAGE = "IsingSampler", J, s, 
        h)
}
