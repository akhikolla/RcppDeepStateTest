function (mat, ip, na) 
{
    e <- get("data.env", .GlobalEnv)
    e[["genos2mat"]][[length(e[["genos2mat"]]) + 1]] <- list(mat = mat, 
        ip = ip, na = na)
    .Call("_diveRsity_genos2mat", mat, ip, na)
}
