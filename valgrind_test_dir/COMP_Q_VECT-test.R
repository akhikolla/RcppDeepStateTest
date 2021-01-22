function (x, p, vp) 
{
    e <- get("data.env", .GlobalEnv)
    e[["COMP_Q_VECT"]][[length(e[["COMP_Q_VECT"]]) + 1]] <- list(x = x, 
        p = p, vp = vp)
    .Call("_HistDAWass_COMP_Q_VECT", PACKAGE = "HistDAWass", 
        x, p, vp)
}
