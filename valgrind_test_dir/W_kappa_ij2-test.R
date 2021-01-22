function (design1, design2, theta, i1, i2, ct) 
{
    e <- get("data.env", .GlobalEnv)
    e[["W_kappa_ij2"]][[length(e[["W_kappa_ij2"]]) + 1]] <- list(design1 = design1, 
        design2 = design2, theta = theta, i1 = i1, i2 = i2, ct = ct)
    .Call("_activegp_W_kappa_ij2", PACKAGE = "activegp", design1, 
        design2, theta, i1, i2, ct)
}
