function (Dx, Dz) 
{
    e <- get("data.env", .GlobalEnv)
    e[["projection"]][[length(e[["projection"]]) + 1]] <- list(Dx = Dx, 
        Dz = Dz)
    .Call("_energy_projection", Dx, Dz)
}
