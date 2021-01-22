function (x) 
{
    e <- get("data.env", .GlobalEnv)
    e[["pz_parse_lon"]][[length(e[["pz_parse_lon"]]) + 1]] <- list(x = x)
    .Call("_parzer_pz_parse_lon", PACKAGE = "parzer", x)
}
