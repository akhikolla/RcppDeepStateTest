function (x) 
{
    e <- get("data.env", .GlobalEnv)
    e[["calc_dist"]][[length(e[["calc_dist"]]) + 1]] <- list(x = x)
    .Call("_energy_calc_dist", x)
}
