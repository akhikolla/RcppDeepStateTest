function (y, w, min_seg, indices) 
{
    e <- get("data.env", .GlobalEnv)
    e[["const_costs"]][[length(e[["const_costs"]]) + 1]] <- list(y = y, 
        w = w, min_seg = min_seg, indices = indices)
    .Call("_RcppDynProg_const_costs", PACKAGE = "RcppDynProg", 
        y, w, min_seg, indices)
}
