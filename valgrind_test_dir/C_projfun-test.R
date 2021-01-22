function (x, z, sgn, nx, nz, p, ndir) 
{
    e <- get("data.env", .GlobalEnv)
    e[["C_projfun"]][[length(e[["C_projfun"]]) + 1]] <- list(x = x, 
        z = z, sgn = sgn, nx = nx, nz = nz, p = p, ndir = ndir)
    .Call("_Qtools_C_projfun", x, z, sgn, nx, nz, p, ndir)
}
