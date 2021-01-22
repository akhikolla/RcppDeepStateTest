function (cc, a) 
{
    e <- get("data.env", .GlobalEnv)
    e[["gc_all"]][[length(e[["gc_all"]]) + 1]] <- list(cc = cc, 
        a = a)
    .Call("_BNSL_gc_all", cc, a)
}
