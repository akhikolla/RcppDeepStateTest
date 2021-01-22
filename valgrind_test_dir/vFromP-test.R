function (p, eps = 1e-08) 
{
    e <- get("data.env", .GlobalEnv)
    e[["vFromP"]][[length(e[["vFromP"]]) + 1]] <- list(p = p, 
        eps = eps)
    .Call("_bsplinePsd_vFromP", p, eps)
}
