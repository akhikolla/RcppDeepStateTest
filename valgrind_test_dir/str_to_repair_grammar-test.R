function (str) 
{
    e <- get("data.env", .GlobalEnv)
    e[["str_to_repair_grammar"]][[length(e[["str_to_repair_grammar"]]) + 
        1]] <- list(str = str)
    .Call("_jmotif_str_to_repair_grammar", PACKAGE = "jmotif", 
        str)
}
