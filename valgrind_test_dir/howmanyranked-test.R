function (pi_inv) 
{
    e <- get("data.env", .GlobalEnv)
    e[["howmanyranked"]][[length(e[["howmanyranked"]]) + 1]] <- list(pi_inv = pi_inv)
    .Call("_PLMIX_howmanyranked", pi_inv)
}
