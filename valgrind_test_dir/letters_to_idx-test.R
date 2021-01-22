function (str) 
{
    e <- get("data.env", .GlobalEnv)
    e[["letters_to_idx"]][[length(e[["letters_to_idx"]]) + 1]] <- list(str = str)
    .Call("_jmotif_letters_to_idx", PACKAGE = "jmotif", str)
}
