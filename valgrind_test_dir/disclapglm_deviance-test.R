function (y, mu, wt) 
{
    e <- get("data.env", .GlobalEnv)
    e[["disclapglm_deviance"]][[length(e[["disclapglm_deviance"]]) + 
        1]] <- list(y = y, mu = mu, wt = wt)
    .Call("_disclapmix_disclapglm_deviance", PACKAGE = "disclapmix", 
        y, mu, wt)
}
