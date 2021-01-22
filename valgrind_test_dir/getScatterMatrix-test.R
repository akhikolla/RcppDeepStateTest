function (II_, X_, H_) 
{
    e <- get("data.env", .GlobalEnv)
    e[["getScatterMatrix"]][[length(e[["getScatterMatrix"]]) + 
        1]] <- list(II_ = II_, X_ = X_, H_ = H_)
    .Call("_kcpRS_getScatterMatrix", PACKAGE = "kcpRS", II_, 
        X_, H_)
}
