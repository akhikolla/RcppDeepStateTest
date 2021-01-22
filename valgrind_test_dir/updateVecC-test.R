function (init_weight, add_index, remove_index, hhsize, hhid, 
    sizefactor) 
{
    e <- get("data.env", .GlobalEnv)
    e[["updateVecC"]][[length(e[["updateVecC"]]) + 1]] <- list(init_weight = init_weight, 
        add_index = add_index, remove_index = remove_index, hhsize = hhsize, 
        hhid = hhid, sizefactor = sizefactor)
    .Call("_simPop_updateVecC", PACKAGE = "simPop", init_weight, 
        add_index, remove_index, hhsize, hhid, sizefactor)
}
