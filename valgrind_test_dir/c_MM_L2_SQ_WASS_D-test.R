function (MM) 
{
    e <- get("data.env", .GlobalEnv)
    e[["c_MM_L2_SQ_WASS_D"]][[length(e[["c_MM_L2_SQ_WASS_D"]]) + 
        1]] <- list(MM = MM)
    .Call("_HistDAWass_c_MM_L2_SQ_WASS_D", PACKAGE = "HistDAWass", 
        MM)
}
