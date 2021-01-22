function (hsum, af, indtyp) 
{
    e <- get("data.env", .GlobalEnv)
    e[["glbWCcpp"]][[length(e[["glbWCcpp"]]) + 1]] <- list(hsum = hsum, 
        af = af, indtyp = indtyp)
    .Call("_diveRsity_glbWCcpp", hsum, af, indtyp)
}
