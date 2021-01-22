function (a_size) 
{
    e <- get("data.env", .GlobalEnv)
    e[["alphabet_to_cuts"]][[length(e[["alphabet_to_cuts"]]) + 
        1]] <- list(a_size = a_size)
    .Call("_jmotif_alphabet_to_cuts", PACKAGE = "jmotif", a_size)
}
