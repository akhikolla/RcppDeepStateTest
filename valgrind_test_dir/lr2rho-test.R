function (lr) 
{
    e <- get("data.env", .GlobalEnv)
    e[["lr2rho"]][[length(e[["lr2rho"]]) + 1]] <- list(lr = lr)
    .Call("_propr_lr2rho", lr)
}
