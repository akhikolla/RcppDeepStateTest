function (cols, x, y, f) 
{
    e <- get("data.env", .GlobalEnv)
    e[["C_disj_conCov"]][[length(e[["C_disj_conCov"]]) + 1]] <- list(cols = cols, 
        x = x, y = y, f = f)
    .Call("_cna_C_disj_conCov", cols, x, y, f)
}
