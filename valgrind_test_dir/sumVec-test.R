function (init_weight, sizefactor) 
{
    e <- get("data.env", .GlobalEnv)
    e[["sumVec"]][[length(e[["sumVec"]]) + 1]] <- list(init_weight = init_weight, 
        sizefactor = sizefactor)
    .Call("_simPop_sumVec", PACKAGE = "simPop", init_weight, 
        sizefactor)
}
