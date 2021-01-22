function () 
{
    e <- get("data.env", .GlobalEnv)
    e[["refrac_extended"]][[length(e[["refrac_extended"]]) + 
        1]] <- list()
    list(NULL, character(0))
}
