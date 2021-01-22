function (x) 
{
    e <- get("data.env", .GlobalEnv)
    e[["pz_parse_parts_lat"]][[length(e[["pz_parse_parts_lat"]]) + 
        1]] <- list(x = x)
    .Call("_parzer_pz_parse_parts_lat", PACKAGE = "parzer", x)
}
