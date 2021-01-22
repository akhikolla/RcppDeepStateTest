function (a, b) 
{
    e <- get("data.env", .GlobalEnv)
    e[["round_down_core_prev"]][[length(e[["round_down_core_prev"]]) + 
        1]] <- list(a = a, b = b)
    .Call("_padr_round_down_core_prev", PACKAGE = "padr", a, 
        b)
}
