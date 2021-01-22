function (y, w, min_seg, i, j) 
{
    e <- get("data.env", .GlobalEnv)
    e[["const_cost_logistic"]][[length(e[["const_cost_logistic"]]) + 
        1]] <- list(y = y, w = w, min_seg = min_seg, i = i, j = j)
    .Call("_RcppDynProg_const_cost_logistic", PACKAGE = "RcppDynProg", 
        y, w, min_seg, i, j)
}
