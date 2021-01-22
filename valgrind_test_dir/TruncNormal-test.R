function (rho, c1) 
{
    e <- get("data.env", .GlobalEnv)
    e[["TruncNormal"]][[length(e[["TruncNormal"]]) + 1]] <- list(rho = rho, 
        c1 = c1)
    .Call("_Phase12Compare_TruncNormal", PACKAGE = "Phase12Compare", 
        rho, c1)
}
