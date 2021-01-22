function (vmat, ncol, nrow, prod) 
{
    e <- get("data.env", .GlobalEnv)
    e[["convertSBtoNormal"]][[length(e[["convertSBtoNormal"]]) + 
        1]] <- list(vmat = vmat, ncol = ncol, nrow = nrow, prod = prod)
    .Call("_Rlda_convertSBtoNormal", vmat, ncol, nrow, prod)
}
