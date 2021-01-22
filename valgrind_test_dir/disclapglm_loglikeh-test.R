function (mu, y) 
{
    e <- get("data.env", .GlobalEnv)
    e[["disclapglm_loglikeh"]][[length(e[["disclapglm_loglikeh"]]) + 
        1]] <- list(mu = mu, y = y)
    .Call("_disclapmix_disclapglm_loglikeh", PACKAGE = "disclapmix", 
        mu, y)
}
