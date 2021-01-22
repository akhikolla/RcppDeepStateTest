function (x_, a_, b_) 
{
    e <- get("data.env", .GlobalEnv)
    e[["computeOneSidedPvalueRcpp"]][[length(e[["computeOneSidedPvalueRcpp"]]) + 
        1]] <- list(x_ = x_, a_ = a_, b_ = b_)
    .Call("_ffstream_computeOneSidedPvalueRcpp", x_, a_, b_)
}
