function (S, r) 
{
    e <- get("data.env", .GlobalEnv)
    e[["es_raw"]][[length(e[["es_raw"]]) + 1]] <- list(S = S, 
        r = r)
    .Call("_gsEasy_es_raw", PACKAGE = "gsEasy", S, r)
}
