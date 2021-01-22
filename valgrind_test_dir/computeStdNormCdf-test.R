function (x_) 
{
    e <- get("data.env", .GlobalEnv)
    e[["computeStdNormCdf"]][[length(e[["computeStdNormCdf"]]) + 
        1]] <- list(x_ = x_)
    .Call("_ffstream_computeStdNormCdf", x_)
}
