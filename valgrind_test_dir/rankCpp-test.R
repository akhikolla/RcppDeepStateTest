function (x) 
{
    e <- get("data.env", .GlobalEnv)
    e[["rankCpp"]][[length(e[["rankCpp"]]) + 1]] <- list(x = x)
    .Call("_easyVerification_rankCpp", x)
}
