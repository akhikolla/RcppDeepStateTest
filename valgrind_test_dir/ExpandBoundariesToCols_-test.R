function (f, v, res, origin, pent) 
{
    e <- get("data.env", .GlobalEnv)
    e[["ExpandBoundariesToCols_"]][[length(e[["ExpandBoundariesToCols_"]]) + 
        1]] <- list(f = f, v = v, res = res, origin = origin, 
        pent = pent)
    .Call("_icosa_ExpandBoundariesToCols_", f, v, res, origin, 
        pent)
}
