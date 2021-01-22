function (X, lr, ivar = 0L) 
{
    e <- get("data.env", .GlobalEnv)
    e[["rhoRcpp"]][[length(e[["rhoRcpp"]]) + 1]] <- list(X = X, 
        lr = lr, ivar = ivar)
    .Call("_propr_rhoRcpp", X, lr, ivar)
}
