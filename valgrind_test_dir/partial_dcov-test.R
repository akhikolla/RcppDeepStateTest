function (Dx, Dy, Dz) 
{
    e <- get("data.env", .GlobalEnv)
    e[["partial_dcov"]][[length(e[["partial_dcov"]]) + 1]] <- list(Dx = Dx, 
        Dy = Dy, Dz = Dz)
    .Call("_energy_partial_dcov", Dx, Dy, Dz)
}
