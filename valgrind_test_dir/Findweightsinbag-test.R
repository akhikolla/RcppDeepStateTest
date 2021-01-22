function (ONv, inbag, WEv, nobs, nnew, ntree, thres, counti, 
    normalise) 
{
    e <- get("data.env", .GlobalEnv)
    e[["Findweightsinbag"]][[length(e[["Findweightsinbag"]]) + 
        1]] <- list(ONv = ONv, inbag = inbag, WEv = WEv, nobs = nobs, 
        nnew = nnew, ntree = ntree, thres = thres, counti = counti, 
        normalise = normalise)
    .Call("_quantregRanger_Findweightsinbag", PACKAGE = "quantregRanger", 
        ONv, inbag, WEv, nobs, nnew, ntree, thres, counti, normalise)
}
