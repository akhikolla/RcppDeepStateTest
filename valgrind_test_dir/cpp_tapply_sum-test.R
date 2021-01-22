function (Q, x, dum) 
{
    e <- get("data.env", .GlobalEnv)
    e[["cpp_tapply_sum"]][[length(e[["cpp_tapply_sum"]]) + 1]] <- list(Q = Q, 
        x = x, dum = dum)
    .Call("_fixest_cpp_tapply_sum", Q, x, dum)
}
