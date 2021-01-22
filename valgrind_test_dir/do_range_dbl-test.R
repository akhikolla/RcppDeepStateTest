function (x, halt_if_min = 1, halt_if_max = -1) 
{
    e <- get("data.env", .GlobalEnv)
    e[["do_range_dbl"]][[length(e[["do_range_dbl"]]) + 1]] <- list(x = x, 
        halt_if_min = halt_if_min, halt_if_max = halt_if_max)
    .Call("_hutilscpp_do_range_dbl", x, halt_if_min, halt_if_max)
}
