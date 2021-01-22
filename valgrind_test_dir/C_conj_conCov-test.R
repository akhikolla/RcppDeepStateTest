function (cols, x, y, f) 
{
    e <- get("data.env", .GlobalEnv)
    e[["C_conj_conCov"]][[length(e[["C_conj_conCov"]]) + 1]] <- list(cols = cols, 
        x = x, y = y, f = f)
    .Call("_cna_C_conj_conCov", cols, x, y, f)
}
