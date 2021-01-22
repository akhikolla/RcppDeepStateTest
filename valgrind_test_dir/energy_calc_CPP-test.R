function (wind_speed, rotor_radius, air_rh) 
{
    e <- get("data.env", .GlobalEnv)
    e[["energy_calc_CPP"]][[length(e[["energy_calc_CPP"]]) + 
        1]] <- list(wind_speed = wind_speed, rotor_radius = rotor_radius, 
        air_rh = air_rh)
    .Call("_windfarmGA_energy_calc_CPP", wind_speed, rotor_radius, 
        air_rh)
}
