function (Yt_, Ft_, delta, m0_, CS0_, n0, d0) 
{
    e <- get("data.env", .GlobalEnv)
    e[["dlmLplCpp"]][[length(e[["dlmLplCpp"]]) + 1]] <- list(Yt_ = Yt_, 
        Ft_ = Ft_, delta = delta, m0_ = m0_, CS0_ = CS0_, n0 = n0, 
        d0 = d0)
    .Call("_multdyn_dlmLplCpp", Yt_, Ft_, delta, m0_, CS0_, n0, 
        d0)
}
