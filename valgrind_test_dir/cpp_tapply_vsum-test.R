function (Q, x, dum) 
{
    e <- get("data.env", .GlobalEnv)
    e[["cpp_tapply_vsum"]][[length(e[["cpp_tapply_vsum"]]) + 
        1]] <- list(Q = Q, x = x, dum = dum)
    .Call("_fixest_cpp_tapply_vsum", Q, x, dum)
}
