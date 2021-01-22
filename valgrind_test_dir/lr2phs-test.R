function (lr) 
{
    e <- get("data.env", .GlobalEnv)
    e[["lr2phs"]][[length(e[["lr2phs"]]) + 1]] <- list(lr = lr)
    .Call("_propr_lr2phs", lr)
}
