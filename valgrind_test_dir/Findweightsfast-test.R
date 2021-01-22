function (OrdNv, NNv, filterednodes, index, newindex, WEv, nobs, 
    nnew, ntree, thres, l) 
{
    e <- get("data.env", .GlobalEnv)
    e[["Findweightsfast"]][[length(e[["Findweightsfast"]]) + 
        1]] <- list(OrdNv = OrdNv, NNv = NNv, filterednodes = filterednodes, 
        index = index, newindex = newindex, WEv = WEv, nobs = nobs, 
        nnew = nnew, ntree = ntree, thres = thres, l = l)
    .Call("_quantregRanger_Findweightsfast", PACKAGE = "quantregRanger", 
        OrdNv, NNv, filterednodes, index, newindex, WEv, nobs, 
        nnew, ntree, thres, l)
}
