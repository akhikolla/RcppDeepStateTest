function (a, b) 
{
    e <- get("data.env", .GlobalEnv)
    e[["round_up_core"]][[length(e[["round_up_core"]]) + 1]] <- list(a = a, 
        b = b)
    .Call("_padr_round_up_core", PACKAGE = "padr", a, b)
}
