function () 
{
    e <- get("data.env", .GlobalEnv)
    e[["fdrseg_cpp"]][[length(e[["fdrseg_cpp"]]) + 1]] <- list()
    list(NULL, character(0))
}
