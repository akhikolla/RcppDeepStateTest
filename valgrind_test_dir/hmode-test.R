function (x, cip) 
{
    e <- get("data.env", .GlobalEnv)
    e[["hmode"]][[length(e[["hmode"]]) + 1]] <- list(x = x, cip = cip)
    .Call("_waspr_hmode", x, cip)
}
