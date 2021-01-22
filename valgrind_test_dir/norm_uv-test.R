function (x, pi, mu, sd, max_iter = 500L, tol = 1e-06) 
{
    e <- get("data.env", .GlobalEnv)
    e[["norm_uv"]][[length(e[["norm_uv"]]) + 1]] <- list(x = x, 
        pi = pi, mu = mu, sd = sd, max_iter = max_iter, tol = tol)
    .Call("_mixR_norm_uv", x, pi, mu, sd, max_iter, tol)
}
