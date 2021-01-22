function (pi_inv) 
{
    e <- get("data.env", .GlobalEnv)
    e[["umat"]][[length(e[["umat"]]) + 1]] <- list(pi_inv = pi_inv)
    .Call("_PLMIX_umat", pi_inv)
}
