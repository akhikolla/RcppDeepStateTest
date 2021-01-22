function (design, theta, i1, i2, ct) 
{
    e <- get("data.env", .GlobalEnv)
    e[["W_kappa_ij"]][[length(e[["W_kappa_ij"]]) + 1]] <- list(design = design, 
        theta = theta, i1 = i1, i2 = i2, ct = ct)
    .Call("_activegp_W_kappa_ij", PACKAGE = "activegp", design, 
        theta, i1, i2, ct)
}
