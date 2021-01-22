function (input, digits) 
{
    e <- get("data.env", .GlobalEnv)
    e[["mid_round"]][[length(e[["mid_round"]]) + 1]] <- list(input = input, 
        digits = digits)
    .Call("_AGread_mid_round", PACKAGE = "AGread", input, digits)
}
