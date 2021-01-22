function (ONv, ONvp, OrdNv, filterednodes, index, newindex, inbag, 
    WEv, WEvp, npred, nobs, ntree, thres, l, countbreak) 
{
    e <- get("data.env", .GlobalEnv)
    e[["Findweightsinbagfastimp"]][[length(e[["Findweightsinbagfastimp"]]) + 
        1]] <- list(ONv = ONv, ONvp = ONvp, OrdNv = OrdNv, filterednodes = filterednodes, 
        index = index, newindex = newindex, inbag = inbag, WEv = WEv, 
        WEvp = WEvp, npred = npred, nobs = nobs, ntree = ntree, 
        thres = thres, l = l, countbreak = countbreak)
    .Call("_quantregRanger_Findweightsinbagfastimp", PACKAGE = "quantregRanger", 
        ONv, ONvp, OrdNv, filterednodes, index, newindex, inbag, 
        WEv, WEvp, npred, nobs, ntree, thres, l, countbreak)
}
