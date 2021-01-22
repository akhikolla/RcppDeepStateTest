function (a, b) 
{
    e <- get("data.env", .GlobalEnv)
    e[["round_down_core"]][[length(e[["round_down_core"]]) + 
        1]] <- list(a = a, b = b)
    .Call("_padr_round_down_core", PACKAGE = "padr", a, b)
}
