function (x, halt_if_min = 1L, halt_if_max = -1L) 
{
    e <- get("data.env", .GlobalEnv)
    e[["do_range_int"]][[length(e[["do_range_int"]]) + 1]] <- list(x = x, 
        halt_if_min = halt_if_min, halt_if_max = halt_if_max)
    .Call("_hutilscpp_do_range_int", x, halt_if_min, halt_if_max)
}
