function (eta) 
{
    e <- get("data.env", .GlobalEnv)
    e[["disclapglm_linkinv"]][[length(e[["disclapglm_linkinv"]]) + 
        1]] <- list(eta = eta)
    .Call("_disclapmix_disclapglm_linkinv", PACKAGE = "disclapmix", 
        eta)
}
