function (y, z) 
{
    e <- get("data.env", .GlobalEnv)
    e[["Btree_sum"]][[length(e[["Btree_sum"]]) + 1]] <- list(y = y, 
        z = z)
    .Call("_energy_Btree_sum", y, z)
}
