function (Dx) 
{
    e <- get("data.env", .GlobalEnv)
    e[["U_center"]][[length(e[["U_center"]]) + 1]] <- list(Dx = Dx)
    .Call("_energy_U_center", Dx)
}
