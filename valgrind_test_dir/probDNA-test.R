function () 
{
    e <- get("data.env", .GlobalEnv)
    e[["probDNA"]][[length(e[["probDNA"]]) + 1]] <- list()
    list(NULL, character(0))
}
