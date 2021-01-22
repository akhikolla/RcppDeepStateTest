function (lr) 
{
    e <- get("data.env", .GlobalEnv)
    e[["lr2phi"]][[length(e[["lr2phi"]]) + 1]] <- list(lr = lr)
    .Call("_propr_lr2phi", lr)
}
