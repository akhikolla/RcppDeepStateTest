function (y, w, min_seg, indices) 
{
    e <- get("data.env", .GlobalEnv)
    e[["const_costs_logistic"]][[length(e[["const_costs_logistic"]]) + 
        1]] <- list(y = y, w = w, min_seg = min_seg, indices = indices)
    .Call("_RcppDynProg_const_costs_logistic", PACKAGE = "RcppDynProg", 
        y, w, min_seg, indices)
}
