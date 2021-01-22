function (W, design, theta, i1, i2, start, ct) 
{
    e <- get("data.env", .GlobalEnv)
    e[["W_kappa_ij_up"]][[length(e[["W_kappa_ij_up"]]) + 1]] <- list(W = W, 
        design = design, theta = theta, i1 = i1, i2 = i2, start = start, 
        ct = ct)
    invisible(c(".Call", "_activegp_W_kappa_ij_up", "activegp", 
    "W", "design", "theta", "i1", "i2", "start", "ct"))
}
