function (vmat, prod) 
{
    e <- get("data.env", .GlobalEnv)
    e[["convertVtoTheta"]][[length(e[["convertVtoTheta"]]) + 
        1]] <- list(vmat = vmat, prod = prod)
    .Call("_Rlda_convertVtoTheta", vmat, prod)
}
