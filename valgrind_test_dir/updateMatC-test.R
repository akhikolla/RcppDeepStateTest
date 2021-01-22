function (M, add_row, add_col, remove_row, remove_col, hhsize, 
    hhid) 
{
    e <- get("data.env", .GlobalEnv)
    e[["updateMatC"]][[length(e[["updateMatC"]]) + 1]] <- list(M = M, 
        add_row = add_row, add_col = add_col, remove_row = remove_row, 
        remove_col = remove_col, hhsize = hhsize, hhid = hhid)
    .Call("_simPop_updateMatC", PACKAGE = "simPop", M, add_row, 
        add_col, remove_row, remove_col, hhsize, hhid)
}
