function (array, pattern) 
{
    e <- get("data.env", .GlobalEnv)
    e[["binary_search_km_ge"]][[length(e[["binary_search_km_ge"]]) + 
        1]] <- list(array = array, pattern = pattern)
    .Call("_KONPsurv_binary_search_km_ge", PACKAGE = "KONPsurv", 
        array, pattern)
}
