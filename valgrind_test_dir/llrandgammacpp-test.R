function (y, lp, tau2, phi, gh) 
{
    e <- get("data.env", .GlobalEnv)
    e[["llrandgammacpp"]][[length(e[["llrandgammacpp"]]) + 1]] <- list(y = y, 
        lp = lp, tau2 = tau2, phi = phi, gh = gh)
    .Call("_robmixglm_llrandgammacpp", y, lp, tau2, phi, gh)
}
