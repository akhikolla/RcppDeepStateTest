function (a, b, rho) 
{
    e <- get("data.env", .GlobalEnv)
    e[["pbivnorm_drezner"]][[length(e[["pbivnorm_drezner"]]) + 
        1]] <- list(a = a, b = b, rho = rho)
    .Call("_immer_pbivnorm_drezner", PACKAGE = "immer", a, b, 
        rho)
}
