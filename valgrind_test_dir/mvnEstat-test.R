function (y) 
{
    e <- get("data.env", .GlobalEnv)
    e[["mvnEstat"]][[length(e[["mvnEstat"]]) + 1]] <- list(y = y)
    .Call("_energy_mvnEstat", y)
}
