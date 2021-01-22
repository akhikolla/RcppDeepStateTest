function (x, y, w, min_seg, indices) 
{
    e <- get("data.env", .GlobalEnv)
    e[["lin_costs"]][[length(e[["lin_costs"]]) + 1]] <- list(x = x, 
        y = y, w = w, min_seg = min_seg, indices = indices)
    .Call("_RcppDynProg_lin_costs", PACKAGE = "RcppDynProg", 
        x, y, w, min_seg, indices)
}
