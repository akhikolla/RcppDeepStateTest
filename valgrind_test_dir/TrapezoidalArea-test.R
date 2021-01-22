function (noise, n_noise, signal, n_signal) 
{
    e <- get("data.env", .GlobalEnv)
    e[["TrapezoidalArea"]][[length(e[["TrapezoidalArea"]]) + 
        1]] <- list(noise = noise, n_noise = n_noise, signal = signal, 
        n_signal = n_signal)
    .Call("_RJafroc_TrapezoidalArea", PACKAGE = "RJafroc", noise, 
        n_noise, signal, n_signal)
}
