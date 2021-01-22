function (v, f) 
{
    e <- get("data.env", .GlobalEnv)
    e[["xxxxyyyyzzzz_"]][[length(e[["xxxxyyyyzzzz_"]]) + 1]] <- list(v = v, 
        f = f)
    .Call("_icosa_xxxxyyyyzzzz_", v, f)
}
