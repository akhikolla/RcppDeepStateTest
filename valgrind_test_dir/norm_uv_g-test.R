function (data, pi, mu, sd, max_iter = 100L, tol = 1e-04) 
{
    e <- get("data.env", .GlobalEnv)
    e[["norm_uv_g"]][[length(e[["norm_uv_g"]]) + 1]] <- list(data = data, 
        pi = pi, mu = mu, sd = sd, max_iter = max_iter, tol = tol)
    .Call("_mixR_norm_uv_g", data, pi, mu, sd, max_iter, tol)
}
