function (time_vector, integrand_1, integrand_2) 
{
    e <- get("data.env", .GlobalEnv)
    e[["convolute_semiMarkov"]][[length(e[["convolute_semiMarkov"]]) + 
        1]] <- list(time_vector = time_vector, integrand_1 = integrand_1, 
        integrand_2 = integrand_2)
    .Call("_ebmstate_convolute_semiMarkov", time_vector, integrand_1, 
        integrand_2)
}
