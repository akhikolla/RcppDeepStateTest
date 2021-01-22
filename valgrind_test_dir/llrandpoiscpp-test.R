function (y, lp, tau2, gh) 
{
    e <- get("data.env", .GlobalEnv)
    e[["llrandpoiscpp"]][[length(e[["llrandpoiscpp"]]) + 1]] <- list(y = y, 
        lp = lp, tau2 = tau2, gh = gh)
    .Call("_robmixglm_llrandpoiscpp", y, lp, tau2, gh)
}
