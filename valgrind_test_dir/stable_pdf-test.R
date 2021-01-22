function (x, pars, parametrization = 0L, tol = 1e-12) 
{
    e <- get("data.env", .GlobalEnv)
    e[["stable_pdf"]][[length(e[["stable_pdf"]]) + 1]] <- list(x = x, 
        pars = pars, parametrization = parametrization, tol = tol)
    .Call("_libstableR_stable_pdf", x, pars, parametrization, 
        tol)
}
