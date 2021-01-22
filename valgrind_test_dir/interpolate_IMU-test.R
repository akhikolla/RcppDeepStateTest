function (original_samples, target_frequency) 
{
    e <- get("data.env", .GlobalEnv)
    e[["interpolate_IMU"]][[length(e[["interpolate_IMU"]]) + 
        1]] <- list(original_samples = original_samples, target_frequency = target_frequency)
    .Call("_AGread_interpolate_IMU", PACKAGE = "AGread", original_samples, 
        target_frequency)
}
