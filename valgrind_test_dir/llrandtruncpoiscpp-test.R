function (y, lp, tau2, gh) 
{
    e <- get("data.env", .GlobalEnv)
    e[["llrandtruncpoiscpp"]][[length(e[["llrandtruncpoiscpp"]]) + 
        1]] <- list(y = y, lp = lp, tau2 = tau2, gh = gh)
    .Call("_robmixglm_llrandtruncpoiscpp", y, lp, tau2, gh)
}
