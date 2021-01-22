function (x_, a_, b_) 
{
    e <- get("data.env", .GlobalEnv)
    e[["computeTwoSidedPvalueRcpp"]][[length(e[["computeTwoSidedPvalueRcpp"]]) + 
        1]] <- list(x_ = x_, a_ = a_, b_ = b_)
    .Call("_ffstream_computeTwoSidedPvalueRcpp", x_, a_, b_)
}
