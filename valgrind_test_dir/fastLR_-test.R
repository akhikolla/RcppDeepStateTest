function (x, y, start, eps_f, eps_g, maxit) 
{
    e <- get("data.env", .GlobalEnv)
    e[["fastLR_"]][[length(e[["fastLR_"]]) + 1]] <- list(x = x, 
        y = y, start = start, eps_f = eps_f, eps_g = eps_g, maxit = maxit)
    .Call("_RcppNumerical_fastLR_", PACKAGE = "RcppNumerical", 
        x, y, start, eps_f, eps_g, maxit)
}
