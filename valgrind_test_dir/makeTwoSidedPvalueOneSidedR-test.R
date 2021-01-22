function (p2_) 
{
    e <- get("data.env", .GlobalEnv)
    e[["makeTwoSidedPvalueOneSidedR"]][[length(e[["makeTwoSidedPvalueOneSidedR"]]) + 
        1]] <- list(p2_ = p2_)
    .Call("_ffstream_makeTwoSidedPvalueOneSidedR", p2_)
}
