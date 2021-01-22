function (array, pattern) 
{
    e <- get("data.env", .GlobalEnv)
    e[["binary_search_km_g"]][[length(e[["binary_search_km_g"]]) + 
        1]] <- list(array = array, pattern = pattern)
    .Call("_KONPsurv_binary_search_km_g", PACKAGE = "KONPsurv", 
        array, pattern)
}
