function (proportion, references) 
{
    e <- get("data.env", .GlobalEnv)
    e[["interval_match"]][[length(e[["interval_match"]]) + 1]] <- list(proportion = proportion, 
        references = references)
    .Call("_AGread_interval_match", PACKAGE = "AGread", proportion, 
        references)
}
