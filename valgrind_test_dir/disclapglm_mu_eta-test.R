function (eta) 
{
    e <- get("data.env", .GlobalEnv)
    e[["disclapglm_mu_eta"]][[length(e[["disclapglm_mu_eta"]]) + 
        1]] <- list(eta = eta)
    .Call("_disclapmix_disclapglm_mu_eta", PACKAGE = "disclapmix", 
        eta)
}
