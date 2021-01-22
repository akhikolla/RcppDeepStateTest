function (int1, int2) 
{
    e <- get("data.env", .GlobalEnv)
    e[["ElegantPairingInt"]][[length(e[["ElegantPairingInt"]]) + 
        1]] <- list(int1 = int1, int2 = int2)
    .Call("_PPRL_ElegantPairingInt", PACKAGE = "PPRL", int1, 
        int2)
}
