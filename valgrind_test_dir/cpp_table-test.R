function (Q, dum) 
{
    e <- get("data.env", .GlobalEnv)
    e[["cpp_table"]][[length(e[["cpp_table"]]) + 1]] <- list(Q = Q, 
        dum = dum)
    .Call("_fixest_cpp_table", Q, dum)
}
