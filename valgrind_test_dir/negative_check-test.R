function (dat) 
{
    e <- get("data.env", .GlobalEnv)
    e[["negative_check"]][[length(e[["negative_check"]]) + 1]] <- list(dat = dat)
    invisible(c(".Call", "_ptsuite_negative_check", "ptsuite", 
    "dat"))
}
