function (x, y, w, min_seg, i, j) 
{
    e <- get("data.env", .GlobalEnv)
    e[["lin_cost"]][[length(e[["lin_cost"]]) + 1]] <- list(x = x, 
        y = y, w = w, min_seg = min_seg, i = i, j = j)
    .Call("_RcppDynProg_lin_cost", PACKAGE = "RcppDynProg", x, 
        y, w, min_seg, i, j)
}
