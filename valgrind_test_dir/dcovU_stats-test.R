function (Dx, Dy) 
{
    e <- get("data.env", .GlobalEnv)
    e[["dcovU_stats"]][[length(e[["dcovU_stats"]]) + 1]] <- list(Dx = Dx, 
        Dy = Dy)
    .Call("_energy_dcovU_stats", Dx, Dy)
}
