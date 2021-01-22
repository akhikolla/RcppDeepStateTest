function (Aa, Bb, Cc) 
{
    e <- get("data.env", .GlobalEnv)
    e[["angles_CPP"]][[length(e[["angles_CPP"]]) + 1]] <- list(Aa = Aa, 
        Bb = Bb, Cc = Cc)
    .Call("_windfarmGA_angles_CPP", Aa, Bb, Cc)
}
