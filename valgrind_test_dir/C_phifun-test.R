function (x, z, nx, nz, B, ndir, ng, taus, minn, maxn) 
{
    e <- get("data.env", .GlobalEnv)
    e[["C_phifun"]][[length(e[["C_phifun"]]) + 1]] <- list(x = x, 
        z = z, nx = nx, nz = nz, B = B, ndir = ndir, ng = ng, 
        taus = taus, minn = minn, maxn = maxn)
    .Call("_Qtools_C_phifun", x, z, nx, nz, B, ndir, ng, taus, 
        minn, maxn)
}
