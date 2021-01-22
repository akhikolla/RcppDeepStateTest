function () 
{
    e <- get("data.env", .GlobalEnv)
    e[["smuce_cpp"]][[length(e[["smuce_cpp"]]) + 1]] <- list()
    list(NULL, character(0))
}
