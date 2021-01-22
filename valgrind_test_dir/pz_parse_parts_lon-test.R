function (x) 
{
    e <- get("data.env", .GlobalEnv)
    e[["pz_parse_parts_lon"]][[length(e[["pz_parse_parts_lon"]]) + 
        1]] <- list(x = x)
    .Call("_parzer_pz_parse_parts_lon", PACKAGE = "parzer", x)
}
