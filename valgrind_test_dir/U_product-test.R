function (U, V) 
{
    e <- get("data.env", .GlobalEnv)
    e[["U_product"]][[length(e[["U_product"]]) + 1]] <- list(U = U, 
        V = V)
    .Call("_energy_U_product", U, V)
}
