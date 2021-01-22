function (proj_str) 
{
    e <- get("data.env", .GlobalEnv)
    e[["proj_to_wkt_cpp"]][[length(e[["proj_to_wkt_cpp"]]) + 
        1]] <- list(proj_str = proj_str)
    .Call("_vapour_proj_to_wkt_cpp", PACKAGE = "vapour", proj_str)
}
