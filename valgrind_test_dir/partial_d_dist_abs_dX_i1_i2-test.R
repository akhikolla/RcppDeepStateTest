function (X1, i1, i2) 
{
    e <- get("data.env", .GlobalEnv)
    e[["partial_d_dist_abs_dX_i1_i2"]][[length(e[["partial_d_dist_abs_dX_i1_i2"]]) + 
        1]] <- list(X1 = X1, i1 = i1, i2 = i2)
    .Call("_hetGP_partial_d_dist_abs_dX_i1_i2", PACKAGE = "hetGP", 
        X1, i1, i2)
}
