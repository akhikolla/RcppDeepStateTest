function (Dx, Dy, Dz) 
{
    e <- get("data.env", .GlobalEnv)
    e[["partial_dcor"]][[length(e[["partial_dcor"]]) + 1]] <- list(Dx = Dx, 
        Dy = Dy, Dz = Dz)
    .Call("_energy_partial_dcor", Dx, Dy, Dz)
}
