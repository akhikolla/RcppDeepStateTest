function (y, w, min_seg, i, j) 
{
    e <- get("data.env", .GlobalEnv)
    e[["const_cost"]][[length(e[["const_cost"]]) + 1]] <- list(y = y, 
        w = w, min_seg = min_seg, i = i, j = j)
    .Call("_RcppDynProg_const_cost", PACKAGE = "RcppDynProg", 
        y, w, min_seg, i, j)
}
