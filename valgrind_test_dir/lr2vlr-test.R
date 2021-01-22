function (lr) 
{
    e <- get("data.env", .GlobalEnv)
    e[["lr2vlr"]][[length(e[["lr2vlr"]]) + 1]] <- list(lr = lr)
    .Call("_propr_lr2vlr", lr)
}
