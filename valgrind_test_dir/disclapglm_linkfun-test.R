function (mu) 
{
    e <- get("data.env", .GlobalEnv)
    e[["disclapglm_linkfun"]][[length(e[["disclapglm_linkfun"]]) + 
        1]] <- list(mu = mu)
    .Call("_disclapmix_disclapglm_linkfun", PACKAGE = "disclapmix", 
        mu)
}
