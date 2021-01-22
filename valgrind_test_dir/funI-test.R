function (col, fam, finsiz, f) 
{
    e <- get("data.env", .GlobalEnv)
    e[["funI"]][[length(e[["funI"]]) + 1]] <- list(col = col, 
        fam = fam, finsiz = finsiz, f = f)
    .Call("_NAM_funI", col, fam, finsiz, f)
}
