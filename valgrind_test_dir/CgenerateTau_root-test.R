function (U, t, a, d) 
{
    e <- get("data.env", .GlobalEnv)
    e[["CgenerateTau_root"]][[length(e[["CgenerateTau_root"]]) + 
        1]] <- list(U = U, t = t, a = a, d = d)
    .Call("_RGeode_CgenerateTau_root", PACKAGE = "RGeode", U, 
        t, a, d)
}
