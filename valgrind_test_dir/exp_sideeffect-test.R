function (p) 
{
    e <- get("data.env", .GlobalEnv)
    e[["exp_sideeffect"]][[length(e[["exp_sideeffect"]]) + 1]] <- list(p = p)
    .Call("_bnclassify_exp_sideeffect", PACKAGE = "bnclassify", 
        p)
}
