function (design1, design2, theta, i1, i2, ct) 
{
    e <- get("data.env", .GlobalEnv)
    e[["grad_W_kappa_ij2_w2"]][[length(e[["grad_W_kappa_ij2_w2"]]) + 
        1]] <- list(design1 = design1, design2 = design2, theta = theta, 
        i1 = i1, i2 = i2, ct = ct)
    .Call("_activegp_grad_W_kappa_ij2_w2", PACKAGE = "activegp", 
        design1, design2, theta, i1, i2, ct)
}
