function (mu) 
{
    e <- get("data.env", .GlobalEnv)
    e[["disclapglm_varfunc"]][[length(e[["disclapglm_varfunc"]]) + 
        1]] <- list(mu = mu)
    .Call("_disclapmix_disclapglm_varfunc", PACKAGE = "disclapmix", 
        mu)
}
