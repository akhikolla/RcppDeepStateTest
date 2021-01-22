function (p1_, p2_) 
{
    e <- get("data.env", .GlobalEnv)
    e[["combineTwoOneSidedPvaluesRcpp"]][[length(e[["combineTwoOneSidedPvaluesRcpp"]]) + 
        1]] <- list(p1_ = p1_, p2_ = p2_)
    .Call("_ffstream_combineTwoOneSidedPvaluesRcpp", p1_, p2_)
}
