function (x, binf, bsup) 
{
    e <- get("data.env", .GlobalEnv)
    e[["vestimates"]][[length(e[["vestimates"]]) + 1]] <- list(x = x, 
        binf = binf, bsup = bsup)
    .Call("_vsgoftest_vestimates", PACKAGE = "vsgoftest", x, 
        binf, bsup)
}
