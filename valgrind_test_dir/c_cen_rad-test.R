function (x) 
{
    e <- get("data.env", .GlobalEnv)
    e[["c_cen_rad"]][[length(e[["c_cen_rad"]]) + 1]] <- list(x = x)
    .Call("_HistDAWass_c_cen_rad", PACKAGE = "HistDAWass", x)
}
