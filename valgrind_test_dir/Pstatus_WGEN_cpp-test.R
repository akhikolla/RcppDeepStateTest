function (parPwd, parPdd, RN, ndays) 
{
    e <- get("data.env", .GlobalEnv)
    e[["Pstatus_WGEN_cpp"]][[length(e[["Pstatus_WGEN_cpp"]]) + 
        1]] <- list(parPwd = parPwd, parPdd = parPdd, RN = RN, 
        ndays = ndays)
    .Call("_foreSIGHT_Pstatus_WGEN_cpp", parPwd, parPdd, RN, 
        ndays)
}
