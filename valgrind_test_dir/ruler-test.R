function (vR, uR, ciR) 
{
    e <- get("data.env", .GlobalEnv)
    e[["ruler"]][[length(e[["ruler"]]) + 1]] <- list(vR = vR, 
        uR = uR, ciR = ciR)
    .Call("_mmsample_ruler", PACKAGE = "mmsample", vR, uR, ciR)
}
