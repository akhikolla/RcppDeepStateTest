function (prodTau, N, SIGMAS, Z) 
{
    e <- get("data.env", .GlobalEnv)
    e[["CgenerateU_root"]][[length(e[["CgenerateU_root"]]) + 
        1]] <- list(prodTau = prodTau, N = N, SIGMAS = SIGMAS, 
        Z = Z)
    .Call("_RGeode_CgenerateU_root", PACKAGE = "RGeode", prodTau, 
        N, SIGMAS, Z)
}
