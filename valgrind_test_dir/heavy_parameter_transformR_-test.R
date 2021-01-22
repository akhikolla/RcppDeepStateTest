function (parameters, K, p, q, O, A, B, pMax1, qMax1) 
{
    e <- get("data.env", .GlobalEnv)
    e[["heavy_parameter_transformR_"]][[length(e[["heavy_parameter_transformR_"]]) + 
        1]] <- list(parameters = parameters, K = K, p = p, q = q, 
        O = O, A = A, B = B, pMax1 = pMax1, qMax1 = qMax1)
    .Call("_highfrequency_heavy_parameter_transformR_", parameters, 
        K, p, q, O, A, B, pMax1, qMax1)
}
