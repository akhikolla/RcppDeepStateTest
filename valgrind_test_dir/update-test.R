function (x, epsilon, rho, phi) 
{
    e <- get("data.env", .GlobalEnv)
    e[["update"]][[length(e[["update"]]) + 1]] <- list(x = x, 
        epsilon = epsilon, rho = rho, phi = phi)
    .Call("_RMPSH_update", x, epsilon, rho, phi)
}
