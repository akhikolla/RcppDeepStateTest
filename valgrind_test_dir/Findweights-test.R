function (ONv, NNv, WEv, nobs, nnew, ntree, thres, counti, normalise) 
{
    e <- get("data.env", .GlobalEnv)
    e[["Findweights"]][[length(e[["Findweights"]]) + 1]] <- list(ONv = ONv, 
        NNv = NNv, WEv = WEv, nobs = nobs, nnew = nnew, ntree = ntree, 
        thres = thres, counti = counti, normalise = normalise)
    .Call("_quantregRanger_Findweights", PACKAGE = "quantregRanger", 
        ONv, NNv, WEv, nobs, nnew, ntree, thres, counti, normalise)
}
