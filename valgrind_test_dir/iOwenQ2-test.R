function (nu, t, delta, R, subdiv = 100L, eps_abs = 1e-14, eps_rel = 1e-14) 
{
    e <- get("data.env", .GlobalEnv)
    e[["iOwenQ2"]][[length(e[["iOwenQ2"]]) + 1]] <- list(nu = nu, 
        t = t, delta = delta, R = R, subdiv = subdiv, eps_abs = eps_abs, 
        eps_rel = eps_rel)
    .Call("_OwenQ_iOwenQ2", PACKAGE = "OwenQ", nu, t, delta, 
        R, subdiv, eps_abs, eps_rel)
}
