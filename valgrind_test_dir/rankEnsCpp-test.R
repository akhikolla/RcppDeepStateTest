function (ens) 
{
    e <- get("data.env", .GlobalEnv)
    e[["rankEnsCpp"]][[length(e[["rankEnsCpp"]]) + 1]] <- list(ens = ens)
    .Call("_easyVerification_rankEnsCpp", ens)
}
