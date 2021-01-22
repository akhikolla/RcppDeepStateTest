function (y, z, l, h) 
{
    e <- get("data.env", .GlobalEnv)
    e[["c_d_theta_sh_h_p"]][[length(e[["c_d_theta_sh_h_p"]]) + 
        1]] <- list(y = y, z = z, l = l, h = h)
    .Call("_cgAUC_c_d_theta_sh_h_p", PACKAGE = "cgAUC", y, z, 
        l, h)
}
