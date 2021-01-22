function (data, pi, mu, sd, max_iter = 1000L, tol = 1e-04) 
{
    e <- get("data.env", .GlobalEnv)
    e[["norm_ev_g"]][[length(e[["norm_ev_g"]]) + 1]] <- list(data = data, 
        pi = pi, mu = mu, sd = sd, max_iter = max_iter, tol = tol)
    .Call("_mixR_norm_ev_g", data, pi, mu, sd, max_iter, tol)
}
