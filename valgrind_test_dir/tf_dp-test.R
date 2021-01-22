function (n, y, lam) 
{
    e <- get("data.env", .GlobalEnv)
    e[["tf_dp"]][[length(e[["tf_dp"]]) + 1]] <- list(n = n, y = y, 
        lam = lam)
    .Call("_flam_tf_dp", PACKAGE = "flam", n, y, lam)
}
