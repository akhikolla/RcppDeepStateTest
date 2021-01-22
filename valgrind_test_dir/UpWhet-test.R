function (z_hat, alpha0) 
{
    e <- get("data.env", .GlobalEnv)
    e[["UpWhet"]][[length(e[["UpWhet"]]) + 1]] <- list(z_hat = z_hat, 
        alpha0 = alpha0)
    .Call("_PLMIX_UpWhet", z_hat, alpha0)
}
