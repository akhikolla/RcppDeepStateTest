function (test) 
{
    e <- get("data.env", .GlobalEnv)
    e[["crtTest"]][[length(e[["crtTest"]]) + 1]] <- list(test = test)
    .Call("_psrwe_crtTest", test)
}
