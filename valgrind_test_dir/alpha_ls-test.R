function (dat) 
{
    e <- get("data.env", .GlobalEnv)
    e[["alpha_ls"]][[length(e[["alpha_ls"]]) + 1]] <- list(dat = dat)
    .Call("_ptsuite_alpha_ls", PACKAGE = "ptsuite", dat)
}
