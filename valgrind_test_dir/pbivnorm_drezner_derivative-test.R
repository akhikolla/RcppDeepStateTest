function (a, b, rho) 
{
    e <- get("data.env", .GlobalEnv)
    e[["pbivnorm_drezner_derivative"]][[length(e[["pbivnorm_drezner_derivative"]]) + 
        1]] <- list(a = a, b = b, rho = rho)
    .Call("_immer_pbivnorm_drezner_derivative", PACKAGE = "immer", 
        a, b, rho)
}
