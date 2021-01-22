function (dat) 
{
    e <- get("data.env", .GlobalEnv)
    e[["alpha_moment"]][[length(e[["alpha_moment"]]) + 1]] <- list(dat = dat)
    .Call("_ptsuite_alpha_moment", PACKAGE = "ptsuite", dat)
}
