function (Dx) 
{
    e <- get("data.env", .GlobalEnv)
    e[["D_center"]][[length(e[["D_center"]]) + 1]] <- list(Dx = Dx)
    .Call("_energy_D_center", Dx)
}
