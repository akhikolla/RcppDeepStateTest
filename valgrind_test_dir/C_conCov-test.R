function (x, y, f) 
{
    e <- get("data.env", .GlobalEnv)
    e[["C_conCov"]][[length(e[["C_conCov"]]) + 1]] <- list(x = x, 
        y = y, f = f)
    .Call("_cna_C_conCov", x, y, f)
}
