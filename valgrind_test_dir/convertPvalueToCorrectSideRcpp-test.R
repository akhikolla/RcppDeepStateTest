function (p_) 
{
    e <- get("data.env", .GlobalEnv)
    e[["convertPvalueToCorrectSideRcpp"]][[length(e[["convertPvalueToCorrectSideRcpp"]]) + 
        1]] <- list(p_ = p_)
    .Call("_ffstream_convertPvalueToCorrectSideRcpp", p_)
}
