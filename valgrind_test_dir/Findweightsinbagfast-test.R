function (ONv, OrdNv, filterednodes, index, newindex, inbag, 
    WEv, nobs, ntree, thres, l) 
{
    e <- get("data.env", .GlobalEnv)
    e[["Findweightsinbagfast"]][[length(e[["Findweightsinbagfast"]]) + 
        1]] <- list(ONv = ONv, OrdNv = OrdNv, filterednodes = filterednodes, 
        index = index, newindex = newindex, inbag = inbag, WEv = WEv, 
        nobs = nobs, ntree = ntree, thres = thres, l = l)
    .Call("_quantregRanger_Findweightsinbagfast", PACKAGE = "quantregRanger", 
        ONv, OrdNv, filterednodes, index, newindex, inbag, WEv, 
        nobs, ntree, thres, l)
}
