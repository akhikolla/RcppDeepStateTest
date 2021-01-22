function (nu, t, delta, R, subdiv = 100L, eps_abs = 1e-14, eps_rel = 1e-14) 
{
    e <- get("data.env", .GlobalEnv)
    e[["iOwenQ1"]][[length(e[["iOwenQ1"]]) + 1]] <- list(nu = nu, 
        t = t, delta = delta, R = R, subdiv = subdiv, eps_abs = eps_abs, 
        eps_rel = eps_rel)
    .Call("_OwenQ_iOwenQ1", PACKAGE = "OwenQ", nu, t, delta, 
        R, subdiv, eps_abs, eps_rel)
}
