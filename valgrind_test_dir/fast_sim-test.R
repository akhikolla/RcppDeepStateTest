function (prot, mat) 
{
    e <- get("data.env", .GlobalEnv)
    e[["fast_sim"]][[length(e[["fast_sim"]]) + 1]] <- list(prot = prot, 
        mat = mat)
    .Call("_imp4p_fast_sim", PACKAGE = "imp4p", prot, mat)
}
