function (nu, t1, t2, delta1, delta2, subdiv = 100L, eps_abs = 1e-14, 
    eps_rel = 1e-14) 
{
    e <- get("data.env", .GlobalEnv)
    e[["ipowen4"]][[length(e[["ipowen4"]]) + 1]] <- list(nu = nu, 
        t1 = t1, t2 = t2, delta1 = delta1, delta2 = delta2, subdiv = subdiv, 
        eps_abs = eps_abs, eps_rel = eps_rel)
    .Call("_OwenQ_ipowen4", PACKAGE = "OwenQ", nu, t1, t2, delta1, 
        delta2, subdiv, eps_abs, eps_rel)
}
