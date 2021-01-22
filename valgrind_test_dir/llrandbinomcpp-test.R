function (y, lp, tau2, gh) 
{
    e <- get("data.env", .GlobalEnv)
    e[["llrandbinomcpp"]][[length(e[["llrandbinomcpp"]]) + 1]] <- list(y = y, 
        lp = lp, tau2 = tau2, gh = gh)
    .Call("_robmixglm_llrandbinomcpp", y, lp, tau2, gh)
}
