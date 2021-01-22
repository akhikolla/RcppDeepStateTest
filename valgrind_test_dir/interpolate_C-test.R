function (original_samples, target_frequency) 
{
    e <- get("data.env", .GlobalEnv)
    e[["interpolate_C"]][[length(e[["interpolate_C"]]) + 1]] <- list(original_samples = original_samples, 
        target_frequency = target_frequency)
    .Call("_AGread_interpolate_C", PACKAGE = "AGread", original_samples, 
        target_frequency)
}
