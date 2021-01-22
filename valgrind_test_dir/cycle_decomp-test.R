function (comp) 
{
    e <- get("data.env", .GlobalEnv)
    e[["cycle_decomp"]][[length(e[["cycle_decomp"]]) + 1]] <- list(comp = comp)
    .Call("_rankdist_cycle_decomp", comp)
}
